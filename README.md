*This project has been created as part of the 42 curriculum by kkomurat.*

# ft_printf

## Description
ft_printf is a custom implementation of the C standard `printf` function.  
The goal of this project is to understand variadic functions and formatted output by reimplementing `printf` from scratch.

## Instructions
### Compilation
```bash
make        # Compile the library (generates libftprintf.a)
make all    # Same as make (explicit target)
make clean  # Remove object files (.o)
make fclean # Remove object files and library (libftprintf.a)
make re     # Recompile everything from scratch
```
> `make` and `make all` are equivalent. Running either will compile all source files and generate `libftprintf.a`.

### Usage
To use the library in your project, link it at compile time:
```bash
cc main.c libftprintf.a -o my_program
```
And include the header in your source files:
```c
#include "ft_printf.h"
```

## Supported Conversions
| Specifier | Description |
|---|---|
| `%c` | Prints a single character |
| `%s` | Prints a string (`NULL` is printed as `(null)`) |
| `%p` | Prints a pointer address in hexadecimal (`0x...`) |
| `%d` | Prints a decimal integer |
| `%i` | Prints an integer |
| `%u` | Prints an unsigned decimal integer |
| `%x` | Prints a number in lowercase hexadecimal |
| `%X` | Prints a number in uppercase hexadecimal |
| `%%` | Prints a literal `%` character |

## Return Value
`ft_printf` returns the total number of characters printed, or `-1` on error.

## Resources
- 42 Subject PDF (ft_printf)
- Manual pages (`man <function_name>`)
- [klibc vsnprintf.c source code](https://git.kernel.org/pub/scm/libs/klibc/klibc.git/tree/usr/klibc/vsnprintf.c)
- [cppreference.com - fprintf reference](https://en.cppreference.com/c/io/fprintf)

## AI Usage
AI was used for:
- Debugging issues
- Reviewing code structure
- Help with creating README

All code was written and tested manually.

