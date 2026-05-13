*This project has been created as part of the 42 curriculum by kkomurat.*

# Libft

## Description

Libft is a custom C library.  
The goal of this project is to understand how C standard functions work by reimplementing them from scratch and learning how to use them effectively.

## Instructions

### Compilation

```bash
make        # Compile the library (generates libft.a)
make all    # Same as make (explicit target)
make clean  # Remove object files (.o)
make fclean # Remove object files and library (libft.a)
make re     # Recompile everything from scratch
```

> `make` and `make all` are equivalent. Running either will compile all source files and generate `libft.a`.

### Usage

To use the library in your project, link it at compile time:

```bash
cc main.c -L. -lft -o my_program
```

And include the header in your source files:

```c
#include "libft.h"
```

## Implemented Functions

### Part 1 — Libc Functions

| Function | Description |
|---|---|
| `ft_isalpha` | Checks if character is alphabetic |
| `ft_isdigit` | Checks if character is a digit |
| `ft_isalnum` | Checks if character is alphanumeric |
| `ft_isascii` | Checks if character is ASCII |
| `ft_isprint` | Checks if character is printable |
| `ft_strlen` | Returns length of a string |
| `ft_memset` | Fills memory with a constant byte |
| `ft_bzero` | Zeroes out memory |
| `ft_memcpy` | Copies memory area |
| `ft_memmove` | Copies memory area (handles overlap) |
| `ft_strlcpy` | Size-bounded string copy |
| `ft_strlcat` | Size-bounded string concatenation |
| `ft_toupper` | Converts character to uppercase |
| `ft_tolower` | Converts character to lowercase |
| `ft_strchr` | Locates first occurrence of character in string |
| `ft_strrchr` | Locates last occurrence of character in string |
| `ft_strncmp` | Compares two strings up to n bytes |
| `ft_memchr` | Scans memory for a character |
| `ft_memcmp` | Compares memory areas |
| `ft_strnstr` | Locates a substring in a string |
| `ft_atoi` | Converts string to integer |
| `ft_calloc` | Allocates and zeroes memory |
| `ft_strdup` | Duplicates a string |

### Part 2 — Additional Functions

| Function | Description |
|---|---|
| `ft_substr` | Extracts a substring from a string |
| `ft_strjoin` | Joins two strings |
| `ft_strtrim` | Trims characters from both ends of a string |
| `ft_split` | Splits a string by a delimiter |
| `ft_itoa` | Converts integer to string |
| `ft_strmapi` | Applies a function to each character (returns new string) |
| `ft_striteri` | Applies a function to each character (in-place) |
| `ft_putchar_fd` | Outputs a character to a file descriptor |
| `ft_putstr_fd` | Outputs a string to a file descriptor |
| `ft_putendl_fd` | Outputs a string followed by newline to a file descriptor |
| `ft_putnbr_fd` | Outputs an integer to a file descriptor |

### Part 3 — Linked List Functions

| Function | Description |
|---|---|
| `ft_lstnew` | Creates a new list node |
| `ft_lstadd_front` | Adds a node at the front of the list |
| `ft_lstsize` | Returns the number of nodes in a list |
| `ft_lstlast` | Returns the last node of a list |
| `ft_lstadd_back` | Adds a node at the back of the list |
| `ft_lstdelone` | Deletes a single node |
| `ft_lstclear` | Deletes and frees all nodes |
| `ft_lstiter` | Applies a function to each node |
| `ft_lstmap` | Applies a function to each node and creates a new list |

## Resources

- 42 Subject PDF (Libft)
- Manual pages (`man <function_name>`)

## AI Usage

AI was used for:
- Debugging issues
- Reviewing code structure

All code was written and tested manually.
