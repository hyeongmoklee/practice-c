#include <stdio.h>

#define IN 1
#define OUT 0

int main()
{
    int c;
    int state;
    int count = 0;

    while ((c = getchar()) != EOF) {
        if (state == IN && (c == ' ' || c == '\t' || c == '\n')) {
            state = OUT;
            for (int i = 0; i < count; i++) {
                printf("=");
                if (i == (count - 1)) {
                    printf("\n");
                }
            }
            count = 0;
        } else if (c == ' ' || c == '\t' || c == '\n') {
            state = OUT;
        } else {
            state = IN;
            count++;
        }
    }
}   
