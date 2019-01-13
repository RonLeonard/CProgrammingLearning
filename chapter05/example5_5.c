#include <stdio.h>

/******array subscript version*****/
void strcpy(char *s, char *t)
{
    int i = 0;
    //while ((*(s + i) = *(t + i)) != '\n')
    while ((s[i] = t[i]) != '\0')
        i++;
}



/******copy t to s, pointer version*******/
void strcpy(char *s, char *t)
{
    while (*s++ = *t++)
    {
        //s++;
        //t++;
        ;
    }
}


int strcmp(char *s, char *t)
{
    int i;
    for (i = 0; s[i] == t[i]; i++) {
        if (s[i] == '\0')
            return 0;
    }

    return s[i] - t[i];
}

int strcmp(char *s, char *t)
{
    for (; *s == *t; s++, t++) {
        if (*s == '\0')
            return 0;
    }
    return *s - *t;
}
