#include <stdio.h>

/****my version******/
int my_strend(char *s, char *t)
{
    int i = 0;
    while (*s) {
        ++s;
    }
    while (*(t + i)) {  //there is a bug, cause maybe the length of s is smaller than t.
        s--;
        i++;
    }

//    while (*s++ == *t++) { //there is a bug at here.
    for (; *s == *t; s++, t++) {
        if (*s == '\0')
            return 1;
    }
    return 0;
}


int strlen(char *s)
{
    int len = 0;
    while (*s) {
        s++;
        len++;
    }   
    return len;   
}

int strcmp(char *s, char *t)
{
    for (; *s == *t; s++, t++) {
        if (*s == '\0')
            return 0;
    }
    return *s - *t;
}


int strend(char *s, char *t)
{
    int s_len = 0, t_len = 0;
    int res = 0;

    s_len = strlen(s);
    t_len = strlen(t);
    if (t_len <= s_len) {
        s += s_len - t_len;
        if (0 == strcmp(s, t))
            res = 1;
    }

    return res;
}


int main(int argc, char **argv)
{
    char *s1 = "The C Programming Language.";
    char *s2 = "Language.";
    char *s3 = "Language";
    if (strend(s1, s2)) {
        printf("The string (%s) has (%s) at the end.\n", s1, s2);
    }
    else {
        printf("The string (%s) doesn't have (%s) at the end.\n", s1, s2);
    }
    
    if (strend(s1, s3)) {
        printf("The string (%s) has (%s) at the end.\n", s1, s3);
    }
    else {
        printf("The string (%s) doesn't have (%s) at the end.\n", s1, s3);
    }
    
    return 0;
}

