#include <stdio.h>

/*
* Created by Gabriel Hugi.
*/



extern size_t mystrlen(const char *str) {
    size_t x = 0;
    while (str[x] != '\0' && str[x] != EOF) {
        x++;
    }
    return x;
}

extern int removefgetsnewline (char *str) {
    int x = 0;
    while (str[x] != '\0') {
        x++;
    }
    str[x-1] = '\0';
    return 0;
}

extern int mystrcpy (char *str, const char* copy) {
    int n;
    n = mystrlen(str);
    if (n < mystrlen(copy)) n = mystrlen(copy);
    while (n >= 0) {
        str[n] = copy[n];
        n--;
    }
    return 0;
}

extern int mystrncpy (char* str, const char* copy, size_t d) {
    int n = 0;
    while (n <= d-1) {
        str[n] = copy[n];
        n++;
    }
    return 0;
}

extern int mystrcat (char *str, const char *cat) {
    int n = 0, n2 = 0;
    while (str[n] != '\0') {
        n++;
    }
    while (cat[n2] != '\0' && cat[n2] != EOF) {
        str[n] = cat[n2];
        n++;
        n2++;
    }
    str[n] = cat[n2];
    return 0;
}

extern int mystrncat (char *str, const char *cat, size_t d) {
    int n = 0, n2 = 0;
    while (str[n] != '\0') {
        n++;
    }
    while (cat[n2] != '\0' && cat[n2] != EOF && n2 <= d-1) {
        str[n] = cat[n2];
        n++;
        n2++;
    }
    n2 = mystrlen(cat);
    str[n] = cat[n2];
    return 0;
}

extern int mystrcmp (const char *str, const char *comp) {
    int n = 0, max = mystrlen(str);
    if (max < mystrlen(comp)) max = mystrlen(comp);
    while (n <= max-1) {
        if (str[n] != comp[n]) {
            int ascii = str[n], ascii2 = comp[n];
            if (ascii > ascii2) {
                return 1;
            }
            else {
                return -1;
            }
        }
        n++;
    }
    return 0;
}

extern int mystrncmp (const char *str, const char *comp, size_t d) {
    int n = 0;
    while (n <= d-1) {
        if (str[n] != comp[n]) {
            int ascii = str[n], ascii2 = comp[n];
            if (ascii > ascii2) {
                return 1;
            }
            else {
                return -1;
            }
        }
        n++;
    }
    return 0;
}


extern char *mystrchr (const char *str, int b) {
    const char search = b;
    while (*str != '\0'){
        if (*str == search) return (char *)str;
        str++;
    }
    return NULL;
}

extern char *mystrrchr (const char *str, int b) {
    const char search = b;
    const char *returnvalue;
    while (*str != '\0'){
        if (*str == search) returnvalue = str;
        str++;
    }
    return (char *)returnvalue;

}

extern char *mystrstr (const char *str, const char *substr) {
    const int strlenght = mystrlen(str), substrlenght = mystrlen(substr);
    if (strlenght < substrlenght) return NULL;
    int x1 = 0, x2 = 0, n1 = strlenght, n2 = substrlenght;
    for (;x1 <= n1; x1++) {
        if(str[x1] == substr[x2]) x2++;
        else x2 = 0;
        if(x2 == substrlenght) {
            str = &str[x1 - (substrlenght-1)];
            return (char *)str;
        }
    }
    return NULL;

}

extern size_t mystrcspn (const char *str, const char *str2) {
    size_t n = 0;
    for(; str[n] != '\0'; n++) {
        for(size_t n2 = 0; str2[n2] != '\0'; n2++) {
            if (str[n] == str2[n2]) return n;
        }
    }
    return n;
}

extern size_t mystrspn (const char *str, const char *str2) {
    size_t n = 0;
    size_t count = 0;
    size_t d = mystrlen(str2);
    for(; str[n] != '\0'; n++) {
        for(size_t n2 = 0; str2[n2] != '\0'; n2++) {
            if (str[n] != str2[n2]) count++;;
        }
        if(count == d) return n;
        else count = 0;
    }
    return n;
}

extern char *mystrpbrk (const char *str, const char *str2) {
    size_t n = 0;
    const char *char1;
    for(; str[n] != '\0'; n++) {
        for(size_t n2 = 0; str2[n2] != '\0'; n2++) {
            if (str[n] == str2[n2]) {
                char1 = &str[n];
                return (char *)char1;
            }
        }
    }
    return NULL;
}

extern char *mystrtok (char *str, const char *str2) {
    static char *save;
    static size_t position;
    size_t n = 0;
    if (str == NULL) {
        n = position;
        save = &save[position+1];
        while (save[n] != '\0') {
            for(size_t n2 = 0; str2[n2] != '\0'; n2++) {
                if(save[n] == str2[n2]) {
                    save[n] = '\0';
                    position = n;
                    return (char *)save;
                }
            }
            n++;
        }   
    }
    else {
        save = str;
        position = 0;
        while (str[n] != '\0') {
            for(size_t n2 = 0; str2[n2] != '\0'; n2++) {
                if(str[n] == str2[n2]) {
                    str[n] = '\0';
                    position = n;
                    return (char *)str;
                }
            }
            n++;
        }   
    }
    
    return NULL;
}
