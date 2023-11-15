#include "nuclei.h"
#include "nuclei_uart.h"
#include "anl_printf.h"
#include <stdarg.h>
#include <stdint.h>


void anl_putchar(char c){
    uart_write(UART0,c);
}


static void printf_c(int c)
{
	anl_putchar(c);
}

static void printf_s(char *p)
{
    while (*p)
        anl_putchar(*(p++));
}

static void printf_d(int val)
{
    char buffer[32];
    char *p = buffer;
    if (val < 0) {
        printf_c('-');
        val = -val;
    }
    while (val || p == buffer) {
        *(p++) = '0' + val % 10;
        val = val / 10;
    }
    while (p != buffer)
        printf_c(*(--p));
}

int anl_printf(const char *format, ...)
{
    int i;
    va_list ap;

    va_start(ap, format);

    for (i = 0; format[i]; i++)
        if (format[i] == '%') {
            while (format[++i]) {
                if (format[i] == 'c') {
                    printf_c(va_arg(ap,int));
                    break;
                }
                if (format[i] == 's') {
                    printf_s(va_arg(ap,char*));
                    break;
                }
                if (format[i] == 'd') {
                    printf_d(va_arg(ap,int));
                    break;
                }
            }
        } else
            printf_c(format[i]);

    va_end(ap);
}


int anl_puts(char *s){
  while (*s) {
    anl_putchar(*s);
    s++;
  }
  anl_putchar('\n');
  return 0;
}
