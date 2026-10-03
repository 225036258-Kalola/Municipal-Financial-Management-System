#ifndef VALIDATION_H
#define VALIDATION_H

#include <stdbool.h>


void clearInputBuffer(void);


int getValidInt(const char *prompt, int min, int max);


double getValidDouble(const char *prompt, double min, double max);


void getValidString(const char *prompt, char *output, int maxLength, bool allowEmpty);


bool getYesNoConfirmation(const char *prompt);

#endif 