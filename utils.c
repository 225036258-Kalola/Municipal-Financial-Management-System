#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utils.h"

// Clears leftover input from stdin buffer
void clearInputBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Trims trailing newline character left by fgets
void trimNewline(char *str) {
    if (str == NULL) return;
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

// Converts a string to uppercase (useful for searching and comparison)
void convertToUpper(char *str) {
    if (str == NULL) return;
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = (char)toupper((unsigned char)str[i]);
    }
}

// Reads string safely and ensures it is not empty
int readString(char *buffer, int maxLen, const char *prompt) {
    while (1) {
        printf("%s", prompt);
        if (fgets(buffer, maxLen, stdin) != NULL) {
            trimNewline(buffer);
            if (strlen(buffer) > 0) {
                return 1;
            } else {
                printf("Error: Input cannot be empty. Please try again.\n");
            }
        } else {
            clearInputBuffer();
        }
    }
}

// Reads an integer bounded within a specific [min, max] range
int readIntRange(const char *prompt, int min, int max) {
    int value;
    int status;

    while (1) {
        printf("%s", prompt);
        status = scanf("%d", &value);
        clearInputBuffer();

        if (status == 1 && value >= min && value <= max) {
            return value;
        }
        printf("Error: Please enter a valid number between %d and %d.\n", min, max);
    }
}

// Reads a double value ensuring it meets a minimum floor (e.g., non-negative salary/budget)
double readDoubleMin(const char *prompt, double min) {
    double value;
    int status;

    while (1) {
        printf("%s", prompt);
        status = scanf("%lf", &value);
        clearInputBuffer();

        if (status == 1 && value >= min) {
            return value;
        }
        printf("Error: Value must be a valid number greater than or equal to N$%.2f.\n", min);
    }
}