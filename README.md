# Libft

<p align="center">
  <img src="https://github.com/mcombeau/mcombeau/blob/main/42_badges/libfte.png" />
</p>

*This project has been created as part of the 42 curriculum by rhrandri.*


## Description
**Libft** is the first personal C library developed during the 42 curriculum.  
The goal of this project is to reimplement a set of standard C library functions and to build additional utility functions that will be reused throughout future projects.

This project focuses on:
- Understanding how standard libc functions work internally
- Managing memory safely and efficiently
- Respecting strict coding rules (Norm, Makefile constraints, no leaks)
- Building a reusable static library (`libft.a`)

The library is divided into three main parts:
1. Reimplementation of libc functions  
2. Additional utility functions  
3. Linked list manipulation functions  

---

## Instructions

### Compilation
- To compile the library, run:
``make``

This will generate the static library libft.a

- Remove object files:
``make clean``

- Remove object files and the library:
``make fclean``

- Recompile everything:
``make re``

## Library Content
### Part 1 — Libc Functions

- Reimplemented standard C functions such as:

1. Character checks (`ft_isalpha`, `ft_isdigit`, …)

2. Memory manipulation (`ft_memcpy`, `ft_memmove`, `ft_memset`, …)

3. String handling (`ft_strlen`, `ft_strlcpy`, `ft_strchr`, …)

4. Conversion utilities (`ft_atoi`, `ft_calloc`, `ft_strdup`)

All functions follow the behavior described in their respective man pages.

## Part 2 — Additional Functions

- Utility functions not directly available in libc, including:

1. String manipulation (`ft_substr`, `ft_strjoin`, `ft_strtrim`, `ft_split`)

2. Conversions (`ft_itoa`)

3. Functional string iteration (`ft_strmapi`, `ft_striteri`)

4. File descriptor output helpers (`ft_putchar_fd`, `ft_putstr_fd`, `ft_putendl_fd`, `ft_putnbr_fd`)

## Part 3 — Linked List Functions

- Implementation of a generic singly linked list using the following structure:

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

- Available linked list utilities:

1. Node creation and insertion (`ft_lstnew`, `ft_lstadd_front`, `ft_lstadd_back`)

2. List inspection (`ft_lstsize`, `ft_lstlast`)

3. Memory management (`ft_lstdelone`, `ft_lstclear`)

4. Iteration and mapping (`ft_lstiter`, `ft_lstmap`)

These functions provide a foundation for dynamic data structures used in later projects.

## Resources

### Documentation & References
Linux man pages (man strlen, man malloc, etc.)

GNU C Library documentation

BSD libc documentation (for strlcpy, strlcat)

42 intranet project documentation

### AI USAGE
AI tools were used strictly as a support tool, never to directly generate solutions.
They were used for:

Debugging assistance

Typo detection

Code readability checks

Verifying edge cases and logic consistency

Minor documentation and formatting help

All algorithmic choices, implementations, and problem-solving were done manually in accordance with the 42 AI usage policy.

## Notes & Disclaimer
The project strictly follows the 42 Norm

All memory allocations are handled carefully to avoid leaks

No global variables are used

The library is intended to be reused in future 42 projects

---
Made by rhrandri: rhrandri@student.42antananarivo.mg
