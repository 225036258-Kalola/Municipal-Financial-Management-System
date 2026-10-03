#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "string_utils.h"

void toUpperCase(char *str) {
    if (!str) return;
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = (char)toupper((unsigned char)str[i]);
    }
}

bool compareStringsIgnoreCase(const char *str1, const char *str2) {
    if (!str1 || !str2) return false;

    char temp1[100];
    char temp2[100];

    strncpy(temp1, str1, sizeof(temp1) - 1);
    temp1[sizeof(temp1) - 1] = '\0';

    strncpy(temp2, str2, sizeof(temp2) - 1);
    temp2[sizeof(temp2) - 1] = '\0';

    toUpperCase(temp1);
    toUpperCase(temp2);

    return (strcmp(temp1, temp2) == 0);
}

void buildSearchQuery(const char *prefix, const char *term, char *dest, size_t destSize) {
    if (!prefix || !term || !dest) return;

    size_t reqLen = strlen(prefix) + strlen(term) + 1;
    if (reqLen > destSize) {
        printf("[WARN] Search term truncated to fit memory constraints.\n");
    }

    strcpy(dest, prefix);
    strcat(dest, term);
}

void safeStringCopy(char *dest, const char *src, size_t destSize) {
    if (!dest || !src || destSize == 0) return;

    if (strlen(src) >= destSize) {
        strncpy(dest, src, destSize - 1);
        dest[destSize - 1] = '\0';
    } else {
        strcpy(dest, src);
    }
}