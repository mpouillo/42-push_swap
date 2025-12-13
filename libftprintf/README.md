# ft_printf

*This project has been created as a part of the 42 curriculum by mpouillo.*

### Description:

ft_printf is a project that requires writing a function reproducing the behavior of the original `printf()` function from `libc`.

The project is a great introduction to variadic functions: functions that accept a variable number of arguments.

In the *bonus* version of the project, the function is able to handle the following flags: `-+ #0.`.

`ft_printf()` parses the string passed as first argument, printing any character it encounters until it reaches a `'%'`. When it does, it parses and stores flags, width and precision into a structure. It then calls the corresponding function depending on the first valid character encountered. Using the values stored in the structure, the function applies each of the flags in the same order as the original `printf()`, then prints the result, and resumes parsing the string until reaching a `'\0'`.

### Usage

Valid conversions:
- %c: Prints a single character.
- %s: Prints a string (as defined by the common C convention).
- %p: The void * pointer argument has to be printed in hexadecimal format.
- %d: Prints a decimal (base 10) number.
- %i: Prints an integer in base 10.
- %u: Prints an unsigned decimal (base 10) number.
- %x: Prints a number in hexadecimal (base 16) lowercase format.
- %X: Prints a number in hexadecimal (base 16) uppercase format.
- %%: Prints a percent sign.

Valid flags are `-+ #0.`. Refer to `man 3 printf` for flags, width and precision usage.

### Instructions

The prototype of `ft_printf()` is:
```c
int ft_printf(const char *, ...)
```

Compile the library with the following command:
```shell
make all
```

To compile with bonuses, run:
```shell
make bonus
```

To use the library, include it with:
```c
#include "ft_printf.h"
```
and compile with the following command:
```shell
cc -Wall -Werror -Wextra your_files.c -L. -lftprintf
```

### Resources:

- [Project link](https://projects.intra.42.fr/projects/42cursus-ft_printf) (requires access to the 42 intra)
- AI was used to create tests to reproduce the original printf's behavior, but not to generate any code for the library itself.
