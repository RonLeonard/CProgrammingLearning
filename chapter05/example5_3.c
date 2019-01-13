#define ALLOCSIZE 10000

static char allocbuf[ALLOCSIZE];

static char *allocp = allocbuf;


char *alloc(int n)
{
    if (allocbuf + ALLOCSIZE - allocp >= n) {
        allocp += n;
        return allocp - n;
    }
    else {
        return 0;
    }
}

void afree(char *p)
{
    if (p >= allocbuf && p < allocbuf + ALLOCSIZE) {
        allocp = p;
    }
}


int strlen(char *s)
{
/***version 01******/
    // int n = 0;
    // for (; *s != '\n'; s++) {
    //     n++;
    // }
    // return n;

    
/***version 02******/
    char *p = s;
    while (*p != '\n')
        p++;
    return p - s;
}


int 