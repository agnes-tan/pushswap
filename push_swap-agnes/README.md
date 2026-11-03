*This project has been created as part of the 42 curriculum by taling and yi-ktan.*

# push_swap

## Description

`push_swap` is a C program that sorts unique signed integers in ascending order
using two stacks, `a` and `b`, and only the eleven permitted operations:
`sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb`, and `rrr`.
The first argument is the top of stack `a`; stack `b` initially is empty.
The program prints its sorting operations, one per line, to standard output.

This implementation builds on the original parsing, stack operations and Turk
sorting sources, adding the Version 1.2 strategy selectors, initial disorder
metric, benchmark reporting, and a bounded Complex strategy.

## Instructions

Build from the project root:

```sh
make
```

Rebuild or remove generated files:

```sh
make re
make clean
make fclean
```

Run a strategy (the default is `--adaptive`):

```sh
./push_swap 5 4 3 2 1
./push_swap --simple 5 4 3 2 1
./push_swap --medium 5 4 3 2 1
./push_swap --complex 5 4 3 2 1
./push_swap --adaptive 5 4 3 2 1
```

Benchmark mode sends statistics to **stderr**, keeping the sorting instructions
on **stdout**:

```sh
./push_swap --bench --adaptive 5 4 3 2 1 > ops.txt 2> bench.txt
cat bench.txt
```

In zsh, test a random input with an array:

```sh
ARG=($(shuf -i 0-9999 -n 500))
./push_swap --complex "${ARG[@]}" > ops.txt
./checker_linux "${ARG[@]}" < ops.txt
wc -l < ops.txt
```

The checker is an **external test utility**, not part of the mandatory
submission. An empty invocation prints nothing; an invalid argument or a
duplicate prints `Error` followed by a newline to stderr.

## Algorithms and complexity

All complexity bounds below refer to the **number of Push_swap operations
printed**, as required by section VI.3.1 of the Version 1.2 subject. They do
**not** necessarily describe CPU time spent analyzing or simulating a plan.
All input numbers are converted into distinct ranks from `0` to `n - 1`.

### Simple — selection/extraction, O(n²)

Find the minimum in stack `a`, bring it to the top by the shorter rotation
direction, push it to `b`, and repeat. Finally push all values back to `a`.
There are `n` extractions, each using at most O(n) rotations. Therefore the
number of emitted operations is O(n²). The input stacks use O(n) memory.

### Medium — bounded moving-window chunks, O(n√n) emitted operations

The Medium strategy first simulates the existing moving-window (K-style)
chunk sorter on a separate copy of the input. This simulation is silent:
no trial instructions are printed. The raw sorter uses a window of about
`1.4 × sqrt(n)` ranks, then extracts maxima from stack `b`.

The wrapper compares its measured operation count with the operation count
of binary LSD radix sorting on `n` indexed elements. If the chunk plan uses
no more operations, it runs that plan on the original stacks; otherwise it
runs radix. If simulation allocation fails, it also uses radix.

For `n >= 2`, radix performs at most `2n × ceil(log₂ n)` operations. Hence
Medium emits at most this many operations, **for every input**, assuming the
simulated plan and actual plan are deterministic and start from identical
stacks. Therefore Medium has an O(n log n) emitted-operation upper bound,
which also implies the subject's O(n√n) upper bound, since `log n = O(√n)`.
This is an *upper bound*, not a claim that the raw K-style chunk algorithm
itself has an O(n√n) worst-case bound.

The silent simulation can take more CPU time and memory than the emitted
operation bound suggests. The proof applies to **printed Push_swap moves**,
not overall CPU running time. The fallback can be slower in move count than
the usual random-input chunk strategy, so test the performance thresholds.

### Complex — bounded adaptive planning, O(n log n) emitted operations

`sort_complex.c` measures two possible sorting plans **silently on independent
copies** of the input stacks:

1. The existing Turk insertion strategy, with combined rotations where useful.
2. The existing Medium moving-window strategy.

It compares these simulated operation counts with the exact operation count of
binary LSD radix sorting for the same `n`. The implementation then executes
**only the shortest eligible plan on the original stacks**. In a failed
allocation during simulation, it safely uses radix without a trial.

The radix fallback (`complex_radix.c`) examines each of the `ceil(log₂ n)`
rank bits, least-significant first. For each bit, every one of the `n`
elements receives exactly one `ra` or `pb`, and each zero-bit element is pushed
back by `pa`. Thus each pass emits at most `2n` operations, and radix emits at
most `2n × ceil(log₂ n)` operations.

Let `T(n)` denote the number of operations **printed** by Complex. Because
Complex chooses a candidate only if its *measured* operation count is no
larger than the radix count, and otherwise emits radix itself:

```
T(n) = min(Turk trial count, Medium trial count, Radix count)
     <= Radix count
     <= 2n * ceil(log2(n))
```

This is a worst-case **O(n log n) Push_swap-output bound** regardless of how
Turk or Medium behave on a particular input. Small inputs (`n <= 5`) use
constant-sized routines. The trials allocate at most O(n) extra stack nodes
at a time, freed before the actual sorting pass; this does *not* assert that
the trial's own CPU runtime is O(n log n). The trial does not print anything
and does not add to the real benchmark counts.

### Adaptive — input disorder thresholds

Before performing any sorting operations, calculate:

```
disorder = number of inversions / (n * (n - 1) / 2)
```

An inversion is a pair `i < j` with `a[i] > a[j]`. Its value is between `0`
(already sorted) and `1` (reverse sorted). The Version 1.2 threshold rules are:

| Disorder | Strategy | Output-operation target |
|---|---|---|
| `d < 0.2` | Simple | O(n²) |
| `0.2 <= d < 0.5` | Medium | O(n√n) — see verification caveat above |
| `d >= 0.5` | Complex | O(n log n), bounded as shown above |

This pre-sort inversion analysis uses O(n²) comparisons but **zero emitted
stack operations**. No strategy flags are required for Adaptive; it is the
default. A forced `--complex` flag always uses the Complex plan, independent of
the disorder value.

## Benchmark and testing

`--bench` prints the initial disorder as a percentage with two decimals, the
selected strategy, its named operation-complexity class, total operation
count, and individual counts for all eleven operations. Statistics appear
only on stderr, and only for moves actually printed to stdout.

Run correctness and benchmark regression tests:

```sh
python3 tests/test_push_swap.py
python3 tests/test_complex_bound.py
norminette
```

After compilation, independently verify with the checker on the **same input**
used to produce the operation file. Do not regenerate `ARG` between generating
instructions and checking them. Test with Valgrind in your own environment:

```sh
valgrind --leak-check=full --error-exitcode=42 ./push_swap --complex 5 4 3 2 1
```

Version 1.2 performance thresholds:

| Random input size | Minimum pass | Good | Excellent |
|---|---:|---:|---:|
| 100 | < 2,000 | < 1,500 | < 700 |
| 500 | < 12,000 | < 8,000 | < 5,500 |

In a local regression sample of 150 random inputs per size for the **new
Complex** implementation: 100-number counts ranged from 521 to 604 (mean
566.8); 500-number counts ranged from 4,775 to 5,278 (mean 5,046.5). All
300 of those trials sorted correctly and met the excellent thresholds.
These observations do **not** guarantee the thresholds for every possible
input or constitute an official 42 evaluation.

## Group contributions

Version 1.2 requires **exactly two learners**. Confirm these logins and verify
these descriptions of the actual work before submitting:

- **yi-ktan:** Original parsing, stack representation and operations, small sorting, and Turk strategy (based on source-file authorship headers).
- **taling:** strategy testing, benchmark and disorder
  features, README review, and validation of the bounded Complex strategy.
- **Both learners:** Review and explain each strategy, inspect AI-assisted code, and attend the peer-evaluation defense together.

## Resources and AI assistance

- **42 Push_swap subject, Version 1.2:** Chapters VI (mandatory algorithms, strategy selectors, benchmarking, performance) and VII (README).
- Binary radix sorting and algorithm-complexity concepts; e.g. Cormen et al.,
  *Introduction to Algorithms*, sections on radix sorting and asymptotic bounds.
- AI was used to review existing C source, suggest and implement a bounded
  strategy-selection method, design regression tests, and
  identify formatting and performance issues.

## Submission notes

Submit C sources, headers, Makefile, `libftprintf` sources and this README to the assigned Git repository. Do not submit generated `.o` files, executables, or temporary operation logs. Run `make re`, `norminette` and the checker in your own 42 environment before evaluation. The separate Medium worst-case bound, any local Norm results after these changes, and both contributor details must be verified before describing the whole mandatory project as finished.
