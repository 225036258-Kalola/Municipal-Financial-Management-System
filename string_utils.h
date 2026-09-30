#ifndef STRING_UTILS_H
#define STRING_UTILS_H

#include <stdbool.h>
#include <stddef.h>


void toUpperCase(char *str);


bool compareStringsIgnoreCase(const char *str1, const char *str2);


void buildSearchQuery(const char *prefix, const char *term, char *dest, size_t destSize);


void safeStringCopy(char *dest, const char *src, size_t destSize);

#endif 