#include "smprintf.h"
#include <stdint.h>
#include <stdio.h>
#include <string.h>

typedef const void* (* ArgReadFunc)(va_list);

struct FormatSpec {
    const char *type; // arg type like: d, u, ld, lu
    ArgReadFunc f_read;
};

const void* fmt_spec_read_i32(va_list);
const void* fmt_spec_read_u32(va_list);
const void* fmt_spec_read_i64(va_list);
const void* fmt_spec_read_u64(va_list);
const void* fmt_spec_read_str(va_list);

FormatSpec fmt_specs[] = {
    { "d", fmt_spec_read_i32 },
    { "u", fmt_spec_read_u32 },
    { "ld", fmt_spec_read_i64 },
    { "lu", fmt_spec_read_u64 },
    { "s", fmt_spec_read_str },
    { NULL, NULL }
};

int vsmprintf(char *s, size_t maxlen, const char *fmt, va_list args);

const void* fmt_spec_read_i32(va_list args) {
    return (const void *)((int64_t)va_arg(args, int32_t));
}

const void* fmt_spec_read_i64(va_list args) {
    return (const void *)(va_arg(args, int64_t));
}

const void* fmt_spec_read_u32(va_list args) {
    return (const void *)((uint64_t)va_arg(args, uint32_t));
}

const void* fmt_spec_read_u64(va_list args) {
    return (const void *)(va_arg(args, uint64_t));
}

const void* fmt_spec_read_str(va_list args) {
    return (const void *)(va_arg(args, const char *));
}

int smprintf(char *s, size_t maxlen, const char *fmt, ...) {
    va_list arg;
    int done;

    va_start(arg, fmt);
    done = vsmprintf(s, maxlen, fmt, arg);
    va_end(arg);

    return done;
}

int vsmprintf(char *s, size_t maxlen, const char *fmt, va_list args) {
    size_t fmt_len = strlen(fmt);
}
