*This project has been created as part of the 42 curriculum by taling.*

# ft_printf

## Description

The `ft_printf` project is about recoding the standard C `printf()`
function. Its goal is to build a reusable formatted-output library while
learning how variadic functions work in C.

The library implements `ft_printf(const char *format, ...)`, which reads
a format string, processes conversion specifiers, retrieves the matching
arguments, writes the formatted output to standard output, and returns
the number of characters written.

### Supported conversions

  Specifier   Behavior
  ----------- -----------------------------------------------------
  `%c`        Prints a single character.
  `%s`        Prints a string.
  `%p`        Prints a pointer address in hexadecimal.
  `%d`        Prints a signed decimal number.
  `%i`        Prints an integer in base 10.
  `%u`        Prints an unsigned decimal number.
  `%x`        Prints an unsigned number in lowercase hexadecimal.
  `%X`        Prints an unsigned number in uppercase hexadecimal.
  `%%`        Prints a percent sign.

## Instructions

### Requirements

-   A C compiler (`cc`)
-   `make`
-   `ar`, to create the static library

### Build

Run the following command from the repository root:

``` sh
make
```

The project should produce `libftprintf.a` at the root of the
repository.

Available Makefile commands:

``` sh
make        # Compile the library
make clean  # Remove object files
make fclean # Remove object files and the library
make re     # Clean and rebuild
```

### Example usage

Include `ft_printf.h` in your C program and link against
`libftprintf.a`:

``` c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello, %s! Number: %d, hex: %x\n", "world", 42, 42);
    return (0);
}
```

For example, if `main.c` is in the repository root:

``` sh
cc -Wall -Wextra -Werror main.c -L. -lftprintf -o demo
./demo
```

Adjust the command if your source files or header are located elsewhere.

## Algorithm and data structure

### Algorithm

The implementation of `ft_printf` can be described as a left-to-right
scan of the format string:

1.  Read the next character in the format string.
2.  If it is not `%`, write the character and increment the output
    count.
3.  If it is `%`, inspect the next character to identify the conversion
    specifier.
4.  Retrieve the corresponding value from the variadic argument list
    using `va_arg`.
5.  Format and write the value according to the conversion.
6.  Add the number of characters written to the total count and continue
    scanning.
7.  Return the total number of characters written.

### Data structures and design choices

The core state needed for this approach is the format string, a
`va_list` representing the variadic arguments, and an integer counter
for the number of characters printed. Conversion-specific helper
functions can handle characters, strings, pointers, signed and unsigned
integers, and hexadecimal output.

This design follows the subject's requirement to reproduce the required
conversions without implementing the original `printf` buffer
management. Processing the format string sequentially keeps the control
flow straightforward, while separating conversions into helper functions
makes the code easier to read, test, and maintain.

*Make sure this explanation matches the actual implementation in your
repository; update it if your code uses a different structure or
algorithm.*

## Resources

-   `printf(3)` manual: run `man 3 printf`.
-   `stdarg(3)` manual: run `man 3 stdarg`.
-   C reference --- variadic functions:
    https://en.cppreference.com/w/c/variadic
-   C reference --- formatted output:
    https://en.cppreference.com/w/c/io/fprintf
-   The official `ft_printf` project subject provided by 42.

### AI usage

AI was used as a learning and support tool during this project.

It was used for:

Understanding the purpose, including the project overview, usage instructions, and explanation of the general format-string parsing approach.
Assisting with the organization and writing of this README.
AI was used for explanation, guidance, and code review. The project was implemented, tested, and verified by the Taling.


## Testing

Compare the output and return value of `ft_printf` with the system
`printf` for each supported conversion. Include edge cases such as empty
strings, zero values, negative integers, null pointers, and the minimum
and maximum values of the relevant integer types.
