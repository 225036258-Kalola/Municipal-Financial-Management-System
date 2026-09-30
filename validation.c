#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "validation.h"

void clearInputBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
     
    }
}

int getValidInt(const char *prompt, int min, int max) {
    int value;
    int status;

    while (1) {
        printf("%s", prompt);
        status = scanf("%d", &value);

        if (status != 1) {
            printf("[ERROR] Invalid entry. Please enter a valid whole number.\n");
            clearInputBuffer();
            continue;
        }

        clearInputBuffer();

        if (value < min || value > max) {
            printf("[ERROR] Choice out of bounds (%d to %d).\n", min, max);
            continue;
        }

        return value;
    }
}

double getValidDouble(const char *prompt, double min, double max) {
    double value;
    int status;

    while (1) {
        printf("%s", prompt);
        status = scanf("%lf", &value);

        if (status != 1) {
            printf("[ERROR] Invalid numeric input. Please enter a decimal number.\n");
            clearInputBuffer();
            continue;
        }

        clearInputBuffer();

        if (value < min || value > max) {
            printf("[ERROR] Value must be between N$%.2f and N$%.2f.\n", min, max);
            continue;
        }

        return value;
    }
}

void getValidString(const char *prompt, char *output, int maxLength, bool allowEmpty) {
    while (1) {
        printf("%s", prompt);
        if (fgets(output, maxLength, stdin) == NULL) {
            printf("[ERROR] Failed to read string input.\n");
            continue;
        }

        // Strip trailing newline character
        size_t len = strlen(output);
        if (len > 0 && output[len - 1] == '\n') {
            output[len - 1] = '\0';
            len--;
        } else if (len == (size_t)(maxLength - 1)) {
            clearInputBuffer();
        }

        if (!allowEmpty && len == 0) {
            printf("[ERROR] Input cannot be left blank.\n");
            continue;
        }

        bool hasData = false;
        for (size_t i = 0; i < len; i++) {
            if (!isspace((unsigned char)output[i])) {
                hasData = true;
                break;
            }
        }

        if (!allowEmpty && !hasData) {
            printf("[ERROR] Input cannot consist only of spaces.\n");
            continue;
        }

        return;
    }
}

bool getYesNoConfirmation(const char *prompt) {
    char response[10];
    while (1) {
        printf("%s (y/n): ", prompt);
        if (fgets(response, sizeof(response), stdin) != NULL) {
            if (response[0] == 'y' || response[0] == 'Y') return true;
            if (response[0] == 'n' || response[0] == 'N') return false;
        }
        printf("[ERROR] Please enter 'y' for Yes or 'n' for No.\n");
    }
}