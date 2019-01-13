#include <stdio.h>

/***my version****/
// void my_strcat(char *s, char *t)
// {
//     while (*s++)
//         ;
//     for (s--; *t != '\0'; s++, t++) {
//         *s = *t;
//     }
//     *s = '\0';
// } 



/*****one of better version*****/
void strcpy(char *s, char *t)
{
    while (*s++ = *t++) {
       ;
    }  
}

void strcat(char *s, char *t)
{
    while (*s) {
        ++s;
    }
    strcpy(s, t);
}

int main(int argc, char **argv)
{
    char _s[] = "I am ";
    char _t[] = "a thing";
    // char *s = "now this is pointer";
    // char *t = s;
    // if (*t)
    //     ++t;
    //printf("++++wonder this line ?++++\n");
    strcat(_s, _t);
    printf("_s = %s\n", _s);
}