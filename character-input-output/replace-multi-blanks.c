#include <stdio.h>

#define IN 1
#define OUT 0

int main()
{
    int c;
    int state;

    while ((c = getchar()) != EOF) {
        if (state == IN && c == ' ') {
            putchar(c);
            state = OUT;
        } else if (c != ' ') {
            putchar(c);
            state = IN;
        }
    }
}
