//
// Created by lisanhu on 5/8/19.
//

#include "mstring.h"

#include <string.h>

#define FREE free
#define STRNDUP strndup
#define STRLEN strlen


mstring ms_own(const char *cstr, size_t l) {
    mstring ms;
    ms.s = STRNDUP(cstr, l);
    ms.cap = l + 1;
    ms.len = l;
    return ms;
}

mstring ms_borrow(char *cstr, size_t l) {
    mstring ms;
    ms.s = cstr;
    ms.cap = 0;
    ms.len = l;
    return ms;
}

void ms_destroy(mstring *ms) {
    if (ms->cap) {
        FREE(ms->s);
    }
    ms->len = 0;
    ms->cap = 0;
    ms->s = NULL;
}

mstring ms_from(char *s, bool own) {
    mstring ms;
    size_t len = STRLEN(s);
    if (own) {
        return ms_own(s, len);
    }
    return ms_borrow(s, len);
}
