#include <stdio.h>

int main()
{
    int c;
    int count = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t' || c == '\n') {
            count++;
        }
    }
    printf("The count of blanks is %d\n", count);
}
