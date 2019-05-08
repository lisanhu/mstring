//
// Created by lisanhu on 5/8/19.
//

#ifndef GACTV2_MSTRING_H
#define GACTV2_MSTRING_H

#include <stdlib.h>
#include <stdbool.h>


#ifdef __cplusplus
extern "C" {
#endif

/**
* The mstring class
*
* @brief A simple string library for personal use
*
* @param l the length of the string
* @param m the memory unit occupied by the object (when the object is borrowing memory from other places, the value should be 0 since it's not taking any particular memory to store the string)
* @param s the memory address of the beginning of the string
*/
typedef struct mstring {
    size_t len, cap;
    char *s;
} mstring;

mstring ms_from(char *s, bool own);

mstring ms_own(const char *cstr, size_t l);

mstring ms_borrow(char *cstr, size_t l);

void ms_destroy(mstring *ms);

#ifdef __cplusplus
};
#endif

#endif //GACTV2_MSTRING_H
