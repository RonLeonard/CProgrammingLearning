#include <stdio.h>
#include <math.h>

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getch(void) 
{
    return (bufp > 0) ? buf[bufp--] : getchar();
}

void ungetch(int c)
{
    if (bufp >= BUFSIZE) 
        printf("ungetch: too many characters\n");
    else 
        buf[bufp++] = c;
}



int getfloat(float *fp)
{
    int ch = 0;
    int sign = 0;
    int fraction = 0;
    int digits = 0;
    while (isspace(ch = getch()))
        ;
    if (!isdigit(ch) && ch != EOF && ch != '+' && ch != '-' && ch != '.') {
        ungetch(ch);
        return 0;
    }

    sign = (ch == '-') ? -1 : 1;
    if (ch == '+' || ch == '-') {
        ch = getch();
        if (!isdigit(ch) && ch != '.') {
            if (ch == EOF) {
                return EOF;
            }
            else {
                ungetch(ch);
                return 0;
            }
        }
    }

    *fp = 0;
    for (; isdigit(ch) || ch == '.'; ch = getch()) {
        if (ch == '.') {
            fraction = 1;
        }
        else {
            if (!fraction) {
                *fp =10 * *fp + (ch - '0');
            }
            else {
                *fp = *fp + (ch - '0') / pow(10, fraction);
                fraction++;
            }
            digits++;
        }
    }

    *fp *= sign;
    if (ch == EOF) {
        return EOF;
    }
    else {
        ungetch(ch);
        return (digits) ? ch : 0;
    }


}



int main(int argc, char *argv[])
{

    int ret;
    do {
        float f;
        fputs("Enter the numbers: ", stdout);
        fflush(stdout);
        ret = getfloat(&f);
        if (ret > 0) {
            printf("You entered: %f\n", f);
        }
    } while(ret > 0);

    if (ret == EOF) {
        puts("Stopped by EOF.");
    }
    else {
        puts("Stopped by bad input.");
    }
    return 0;

}

