#include <stdio.h>
#define MAXLINE 1000

void reverse(char s[]);
int getlen(char s[], int lim);

int main()
{
    int c, len;
    char line[MAXLINE];

    while ((len = getlen(line, MAXLINE)) > 0) {
        reverse(line);
        printf("%s", line);
    }
    return 0;
}

int getlen(char s[], int lim)
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

void reverse(char s[])
{
    int c;
    int i;
    int len;

    i = 0;
    while (s[i] != '\0') {
        i++;
    }

    len = i - 1;
    i = 0;
    while (i < (len / 2)) {
        c = s[i];
        s[i] = s[len - i - 1];
        s[len - i - 1] = c;
        i++;
    }
}
