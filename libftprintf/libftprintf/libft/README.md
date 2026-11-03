*This project has been created as part of the 42 curriculum by Taling.*

Description
Libft

Libft is a C library project from the 42 curriculum. The goal of this project is to create a personal library of commonly used C functions by reimplementing functions from the standard C library and developing additional utility functions.

The project provides a reusable static library called libft.a. This library can be used in future C projects at 42 and helps develop a strong understanding of memory management, pointers, strings, arrays, linked lists, and dynamic memory allocation.

The project is divided into several categories:

Character checking and conversion
String manipulation
Memory manipulation
Conversion functions
File descriptor output functions
Linked list manipulation

The library also includes bonus functions for managing singly linked lists.

Instructions
Compilation

The project uses a Makefile to compile the library.

To compile the mandatory part:

make

This creates the static library:

libft.a

To compile the bonus part:

make bonus

To remove the object files:

make clean

To remove the object files and the library:

make fclean

To remove everything and recompile the library:

make re
Using the Library

Include the library header in your C source file:

#include "libft.h"

Then compile your program together with the library:

cc main.c -L. -lft

The -L. option tells the compiler to look for libraries in the current directory, while -lft links the libft.a library.

Library Description
Character Functions

These functions check or convert characters:

ft_isalpha — checks whether a character is alphabetic.
ft_isdigit — checks whether a character is a digit.
ft_isalnum — checks whether a character is alphanumeric.
ft_isascii — checks whether a character belongs to the ASCII character set.
ft_isprint — checks whether a character is printable.
ft_toupper — converts a lowercase letter to uppercase.
ft_tolower — converts an uppercase letter to lowercase.
String Functions

These functions are used to inspect and manipulate strings:

ft_strlen — calculates the length of a string.
ft_strchr — searches for the first occurrence of a character.
ft_strrchr — searches for the last occurrence of a character.
ft_strncmp — compares two strings up to a specified number of characters.
ft_strnstr — searches for a substring within a string.
ft_strdup — creates a duplicate of a string.
ft_strlcpy — copies a string with a size limit.
ft_strlcat — concatenates strings with a size limit.
Memory Functions

These functions manipulate or allocate memory:

ft_memset — fills a block of memory with a specified byte.
ft_bzero — sets a block of memory to zero.
ft_memcpy — copies a block of memory.
ft_memmove — copies memory while handling overlapping regions safely.
ft_memchr — searches for a byte in a block of memory.
ft_memcmp — compares two blocks of memory.
ft_calloc — allocates memory and initializes it to zero.
Conversion Functions
ft_atoi — converts a string to an integer.
ft_itoa — converts an integer to a string.
String Manipulation Functions

These functions provide additional string utilities:

ft_substr — creates a substring from a string.
ft_strjoin — joins two strings together.
ft_strtrim — removes specified characters from the beginning and end of a string.
ft_split — splits a string into an array of strings using a delimiter.
ft_strmapi — applies a function to each character of a string and creates a new string.
ft_striteri — applies a function to each character of a string.
File Descriptor Functions

These functions write data to a specified file descriptor:

ft_putchar_fd — writes a character.
ft_putstr_fd — writes a string.
ft_putendl_fd — writes a string followed by a newline.
ft_putnbr_fd — writes an integer.
Linked List Functions

The bonus part of Libft provides functions for manipulating singly linked lists:

ft_lstnew — creates a new list node.
ft_lstadd_front — adds a node to the beginning of a list.
ft_lstsize — returns the number of nodes in a list.
ft_lstlast — returns the last node of a list.
ft_lstadd_back — adds a node to the end of a list.
ft_lstdelone — deletes one node.
ft_lstclear — deletes all nodes in a list.
ft_lstiter — applies a function to every node.
ft_lstmap — creates a new list by applying a function to every node.
Technical Choices

The library is written in C and follows the coding standards required by the 42 curriculum.

Memory allocation is handled using malloc, and dynamically allocated memory is released using free.

Functions that manipulate memory use appropriate pointer types and size_t for sizes and indexes.

For ft_calloc, an overflow check is performed before calculating the total allocation size. The allocated memory is then initialized to zero.

The project is compiled into a static library, libft.a, which can be linked with other C programs.

Resources

The following resources were used to understand the required functions and C programming concepts:

C standard library documentation
Linux man pages
man 3 documentation for standard C library functions
42 Libft project subject
C programming references and tutorials
Compiler documentation and error messages

Examples of relevant manual pages include:

man 3 memset
man 3 memcpy
man 3 memmove
man 3 strlen
man 3 calloc
man 3 strdup
AI Usage

AI was used as a learning and support tool during this project.

It was used for:

Understanding the purpose and behavior of functions required by Libft.
Clarifying C concepts such as pointers, void *, size_t, dynamic memory allocation, and memory manipulation.
Understanding the difference between functions such as malloc and calloc.
Reviewing implementations and explaining potential problems or edge cases.
Understanding integer overflow checks in ft_calloc.
Helping interpret compiler errors and improve understanding of C syntax.
Assisting with the organization and writing of this README.

AI was used for explanation, guidance, and code review. The project was implemented, tested, and verified by the Taling.

Project Structure

A typical project structure is:

libft/
├── Makefile
├── README.md
├── libft.h
├── ft_*.c
└── ...

After compilation, object files and the static library are generated according to the rules defined in the Makefile.

Goal

The main goal of Libft is to build a personal C library from scratch while developing a deeper understanding of:

Memory management
Pointers
Strings
Arrays
Dynamic allocation
Function pointers
Linked lists
Static libraries
Makefiles
C programming fundamentals

This library will also serve as a foundation for future projects in the 42 curriculum.
