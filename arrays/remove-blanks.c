// TODO: Writing a program to remove trailing blanks and tabs from each line of input, and to delete entirely blank lines.

#include <stdio.h>
#define MAXLINE 1000

int getlen(char line[], int lim);

int main()
{
    char line[MAXLINE];
    int len;
    int i;

    while ((len = getlen(line, MAXLINE)) > 0) {
        for (i = len - 1; i >= 0; --i) {
            if (line[i] == ' ' || line[i] == '\t' || line[i] == '\n') {
                continue;
            } else {
                line[i + 1] = '\0';
                break;
            }
        }
        if (i == -1) {
            continue;
        }
        printf("%s\n", line);
    }
    return 0;
}

int getlen(char s[], int lim)
{
    int i, c;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++) {
        s[i] = c;
    }
    if (c == '\n') {
        s[i] = c;
        i++;
    }
    s[i] = '\0';

    return i;
}
