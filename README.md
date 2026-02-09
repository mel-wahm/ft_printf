# ft_printf

A custom implementation of the standard C library function `printf`, created as part of the 42 curriculum.

## Description

ft_printf is a recreation of the printf function from the C standard library. This project involves implementing a variadic function that formats and prints data according to format specifiers, handling multiple data types and conversion specifiers.

## Table of Contents

- [Features](#features)
- [Supported Conversions](#supported-conversions)
- [Installation](#installation)
- [Usage](#usage)
- [Project Structure](#project-structure)
- [Function Prototypes](#function-prototypes)
- [Implementation Details](#implementation-details)
- [Examples](#examples)
- [Compilation](#compilation)
- [Author](#author)

## Features

- ✅ Handles multiple format specifiers
- ✅ Supports variadic arguments
- ✅ Returns the number of characters printed
- ✅ Handles NULL pointers gracefully
- ✅ Manages edge cases (INT_MIN, NULL strings, etc.)
- ✅ No buffer management (direct write to stdout)

## Supported Conversions

| Specifier | Description | Example |
|-----------|-------------|---------|
| `%c` | Single character | `ft_printf("%c", 'A')` → A |
| `%s` | String | `ft_printf("%s", "Hello")` → Hello |
| `%p` | Pointer address (hexadecimal) | `ft_printf("%p", ptr)` → 0x7fff5fbff710 |
| `%d` | Signed decimal integer | `ft_printf("%d", -42)` → -42 |
| `%i` | Signed decimal integer | `ft_printf("%i", 42)` → 42 |
| `%u` | Unsigned decimal integer | `ft_printf("%u", 42)` → 42 |
| `%x` | Hexadecimal (lowercase) | `ft_printf("%x", 255)` → ff |
| `%X` | Hexadecimal (uppercase) | `ft_printf("%X", 255)` → FF |
| `%%` | Literal percent sign | `ft_printf("%%")` → % |

## Installation

Clone the repository and compile the library:

```bash
git clone <repository-url>
cd ft_printf
make
```

This will create the `libftprintf.a` static library.

## Usage

Include the header in your C file:

```c
#include "ft_printf.h"
```

Compile your program with the library:

```bash
cc your_program.c -L. -lftprintf -o your_program
```

Example program:

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello, %s!\n", "world");
    ft_printf("Number: %d\n", 42);
    ft_printf("Hex: %x\n", 255);
    return (0);
}
```

## Project Structure

```
ft_printf/
├── ft_printf.h          # Header file with function prototypes
├── ft_printf.c          # Main printf implementation
├── ft_printf_utils.c    # Format specifier handler
├── ft_putchar.c         # Character output
├── ft_putstr.c          # String output
├── ft_putnbr.c          # Signed integer output
├── ft_putun.c           # Unsigned integer output
├── ft_puthex.c          # Lowercase hexadecimal output
├── ft_putupperhex.c     # Uppercase hexadecimal output
├── ft_putaddress.c      # Pointer address output
├── ft_strlen.c          # String length utility
└── Makefile             # Build automation
```

## Function Prototypes

### Main Function
```c
int ft_printf(const char *format, ...);
```

### Helper Functions
```c
int ft_putchar(char c);
int ft_putstr(char *s);
int ft_putnbr(int n);
int ft_putun(unsigned int num);
int ft_puthex(unsigned int n);
int ft_putupperhex(unsigned int num);
int ft_putaddress(unsigned long int n);
int print_args(char s, va_list ap);
size_t ft_strlen(const char *s);
```

## Implementation Details

### Variadic Arguments
The project uses `<stdarg.h>` to handle variadic arguments:
- `va_list` - holds argument information
- `va_start` - initializes the argument list
- `va_arg` - retrieves the next argument
- `va_end` - cleans up the argument list

### Return Value
The function returns the total number of characters printed. In case of error (NULL format string or incomplete format specifier), it returns -1.

### Special Cases Handled

1. **NULL String**: Prints "(null)" instead of crashing
   ```c
   ft_printf("%s", NULL); // Output: (null)
   ```

2. **NULL Pointer**: Prints "(nil)"
   ```c
   ft_printf("%p", NULL); // Output: (nil)
   ```

3. **INT_MIN**: Properly handles the minimum integer value
   ```c
   ft_printf("%d", -2147483648); // Output: -2147483648
   ```

4. **Invalid Format Specifier**: Prints '%' followed by the character
   ```c
   ft_printf("%z"); // Output: %z
   ```

5. **Incomplete Format**: Returns -1 if format string ends with '%'

### Recursive Implementation
Most numeric conversion functions use recursion to handle digit extraction:
- Divides by base (10 for decimal, 16 for hexadecimal)
- Recursively processes higher-order digits
- Prints digits in correct order

## Examples

```c
#include "ft_printf.h"

int main(void)
{
    int count;
    
    // Character and string
    ft_printf("Character: %c\n", 'A');
    ft_printf("String: %s\n", "Hello World");
    
    // Numbers
    ft_printf("Decimal: %d\n", -42);
    ft_printf("Unsigned: %u\n", 42);
    
    // Hexadecimal
    ft_printf("Lowercase hex: %x\n", 255);
    ft_printf("Uppercase hex: %X\n", 255);
    
    // Pointer
    int x = 42;
    ft_printf("Address: %p\n", &x);
    
    // Return value
    count = ft_printf("Count this!\n");
    ft_printf("Characters printed: %d\n", count);
    
    // Multiple conversions
    ft_printf("Mixed: %s %d %c %x\n", "test", 100, '!', 255);
    
    return (0);
}
```

## Compilation

### Makefile Rules

- `make` or `make all` - Compiles the library
- `make clean` - Removes object files
- `make fclean` - Removes object files and the library
- `make re` - Recompiles everything from scratch

### Compilation Flags

The project compiles with strict flags:
- `-Wall` - Enable all warnings
- `-Wextra` - Enable extra warnings
- `-Werror` - Treat warnings as errors

## Testing

To test the function, compare output with the original printf:

```c
#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
    int ret1, ret2;
    
    ret1 = printf("Original: %d %s\n", 42, "test");
    ret2 = ft_printf("Custom:   %d %s\n", 42, "test");
    
    printf("printf returned: %d\n", ret1);
    ft_printf("ft_printf returned: %d\n", ret2);
    
    return (0);
}
```

## Author

**mel-wahm**
- 42 Network Student
- Email: marvin@42.fr

## License

This project is part of the 42 School curriculum.

---

*Created as part of the 42 curriculum - November 2025*
*This read me was fully made by AI (is sucks i know)*