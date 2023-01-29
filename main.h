#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
int _printf(const char *format, ...);
int specifier(va_list *ap, const char **format);
int p_int(va_list *ap, const char **format);
int p_char(va_list *ap, const char **format);
int p_str(va_list *ap, const char **format);
void p_min(int *i, int *min);
int p_bin(va_list *ap, const char **format);

#endif
