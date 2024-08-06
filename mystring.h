#include <stdio.h>
extern size_t mystrlen (const char *str);
extern int removefgetsnewline (char *str);
extern char *mystrcpy (char* str, const char* copy);
extern int mystrncpy (char* str, const char* copy, size_t d);
extern int mystrcat (char *str, const char *cat);
extern int mystrncat (char *str, const char *cat, size_t d);
extern int mystrcmp (const char *str, const char *comp);
extern int mystrncmp (const char *str, const char *comp, size_t d);
extern char *mystrchr (const char *str, int b);
extern char *mystrrchr (const char *str, int b);
extern char *mystrstr (const char *str, const char *substr);
extern size_t mystrcspn (const char *str, const char *str2);
extern size_t mystrspn (const char *str, const char *str2);
extern char *mystrpbrk (const char *str, const char *str2);
extern char *mystrtok (char *str, const char *str2);
