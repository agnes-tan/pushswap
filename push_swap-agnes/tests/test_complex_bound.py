#!/usr/bin/env python3
"""Check output correctness and the rigorous radix-sized operation bound."""
import random
import subprocess
from pathlib import Path

BINARY = Path(__file__).resolve().parents[1] / "push_swap"
MOVES = {"sa", "sb", "ss", "pa", "pb", "ra", "rb", "rr", "rra", "rrb", "rrr"}


def simulate(numbers, operations):
    a, b = list(numbers), []
    for move in operations:
        assert move in MOVES, (move, "Invalid operation")
        if move in ("sa", "ss") and len(a) > 1:
            a[0], a[1] = a[1], a[0]
        if move in ("sb", "ss") and len(b) > 1:
            b[0], b[1] = b[1], b[0]
        if move == "pa" and b:
            a.insert(0, b.pop(0))
        if move == "pb" and a:
            b.insert(0, a.pop(0))
        if move in ("ra", "rr") and len(a) > 1:
            a.append(a.pop(0))
        if move in ("rb", "rr") and len(b) > 1:
            b.append(b.pop(0))
        if move in ("rra", "rrr") and len(a) > 1:
            a.insert(0, a.pop())
        if move in ("rrb", "rrr") and len(b) > 1:
            b.insert(0, b.pop())
    assert a == sorted(numbers) and not b, (a, b)


def radix_bound(n):
    return 2 * n * ((n - 1).bit_length())


def check_case(numbers):
    cmd = [str(BINARY), "--complex", *map(str, numbers)]
    out = subprocess.run(cmd, text=True, capture_output=True, check=True, timeout=40)
    assert not out.stderr, out.stderr
    operations = out.stdout.splitlines()
    simulate(numbers, operations)
    assert len(operations) <= radix_bound(len(numbers))
    return len(operations)


def main():
    random.seed(20261029)
    for n, repeats in ((3, 30), (10, 30), (100, 100), (500, 100)):
        scores = []
        for _ in range(repeats):
            nums = random.sample(range(-1000000, 1000000), n)
            scores.append(check_case(nums))
        scores.extend([check_case(list(range(n, 0, -1))),
                       check_case(list(range(n)))])
        print(f"{n} numbers: {len(scores)} cases, max={max(scores)}, "
              f"radix bound={radix_bound(n)}")
    print("PASS: correctness and bounded output operation count")


if __name__ == "__main__":
    main()
