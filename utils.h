#ifndef UTILS_H
#define UTILS_H

// System Constants
#define MAX_NAME_LEN 50
#define MAX_DEPT_LEN 30
#define MAX_EMAIL_LEN 50
#define MAX_PHONE_LEN 15
#define MAX_LOCATION_LEN 30

// General Utility Declarations
void clearInputBuffer(void);
void trimNewline(char *str);
int readString(char *buffer, int maxLen, const char *prompt);
int readIntRange(const char *prompt, int min, int max);
double readDoubleMin(const char *prompt, double min);
void convertToUpper(char *str);

#endif // UTILS_H