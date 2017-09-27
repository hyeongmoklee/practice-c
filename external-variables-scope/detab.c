// TODO: Write a program detab that replaces tabs in the input with the proper number of blanks to space to the next tab stop. Assume a fixed set of tab stops, say every n columns. Should n be a variable or a symbolic parameter?

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER  1024
#define TAB         '\t'
#define SPACE       ' '

int calculate_spaces(int offset, int tab_size)
{
    return tab_size - (offset % tab_size);
}

int get_line(char s[], int lim)
{
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        s[i] = c;
    }
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

int main()
{
    char buffer[MAX_BUFFER];
    int tab_size = 5;
    int i, j, k, l;

    while (get_line(buffer, MAX_BUFFER) > 0) {
        for (i = 0, l = 0; buffer[i] != '\0'; i++) {
            if (buffer[i] == TAB) {
                j = calculate_spaces(l, tab_size);
                for (k = 0; k < j; k++) {
                    putchar(SPACE);
                    l++;
                }
            } else {
                putchar(buffer[i]);
                l++;
            }
        }
    }

    return 0;
}
