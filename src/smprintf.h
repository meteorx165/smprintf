#ifndef SMPRINTF_H
#define SMPRINTF_H

#include <stddef.h>
#include <stdarg.h>

int smprintf(char *s, size_t maxlen, const char *format, ...);

#endif
