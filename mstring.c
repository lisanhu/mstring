//
// Created by lisanhu on 5/8/19.
//

#include "mmstring.h"

#include <string.h>

#define FREE free
#define STRNDUP strndup
#define STRLEN strlen


mmstring ms_own(const char *cstr, size_t l) {
    mmstring ms;
    ms.s = STRNDUP(cstr, l);
    ms.cap = l + 1;
    ms.len = l;
    return ms;
}

mmstring ms_borrow(char *cstr, size_t l) {
    mmstring ms;
    ms.s = cstr;
    ms.cap = 0;
    ms.len = l;
    return ms;
}

void ms_destroy(mmstring *ms) {
    if (ms->cap) {
        FREE(ms->s);
    }
    ms->len = 0;
    ms->cap = 0;
    ms->s = NULL;
}

mmstring ms_from(char *s, bool own) {
    mmstring ms;
    size_t len = STRLEN(s);
    if (own) {
        return ms_own(s, len);
    }
    return ms_borrow(s, len);
}

size_t ms_to_cstr(mmstring ms, char *buf) {
    strncpy(buf, ms.s, ms.len);
    buf[ms.len] = '\0';
    return ms.len;
}
