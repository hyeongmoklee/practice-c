/********************************************************
 * Write a program entab that replaces strings of blanks
 * by the minimum number of tabs and blanks to achieve
 * the same spacing. Use the same tab stops as for detab.
 * When either a tab or a single blank would suffice to
 * reach a tab stop, which should be given preference?
 *******************************************************/
#include <stdio.h>

#define MAXLINE 1000
#define TAB2SPACE 4

char line[MAXLINE];
int get_line(void);

int main()
{
    int i, t;
    int space_count, len;

    while ((len = get_line()) > 0) 
    {
        space_count = 0;
        for (i = 0; i < len; i++)
        {
            if (line[i] == ' ')
            {
                space_count++;
            }
            if (line[i] != ' ')
            {
                space_count = 0;
            }
            if (space_count == TAB2SPACE)
            {
                // Because we are removing 4 spaces and
                // replacing them with 1 tab we move back
                // three chars and replace the ' ' with a \t
                i -= 3;
                len -= 3;
                line[i] = '\t';
                for (t = i + 1; t < len; t++) {
                    line[t] = line[t + 3];
                }
                space_count = 0;
                line[len] = '\0';
            }
        }
        printf("%s", line);
    }
    return 0;
}

int get_line(void)
{
    int c, i;
    extern char line[];

    for (i = 0; i < MAXLINE - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        line[i] = c;
    }
    if (c == '\n')
    {
        line[i] = c;
        ++i;
    }
    line[i] = '\0';
    return i;
}
