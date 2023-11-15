
#ifndef _ANL_PRINTF_H
#define _ANL_PRINTF_H

#ifdef __cplusplus
 extern "C" {
#endif

int anl_puts(char *s);

void anl_putchar(char c);

static void printf_c(int c);

static void printf_s(char *p);

static void printf_d(int val);

int anl_printf(const char *format, ...);

#ifdef __cplusplus
}
#endif
#endif /* _ANL_PRINTF_H */

