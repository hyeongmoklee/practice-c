#include <stdio.h>

typedef int bool;
enum {
    false,
    true
};

#define IN 1
#define OUT 0

int main()
{
    int c;
    int state;
    bool dirty;

    while ((c = getchar()) != EOF) {
        if (dirty && state == IN && (c == '\t' || c == ' ')) {
            putchar('\n');
            state = OUT;
        } else if (c == '\t' || c == ' ') {
            // nothing to do.
        } else {
            putchar(c);
            state = IN;
            dirty = true;
        }
    }
}
