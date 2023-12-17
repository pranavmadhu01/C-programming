#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int n;
char p[20][20], f[20];
int k = 0;

void first(char c);
void follow(char c);
int main()
{
    int ch=1;
    char c;
    printf("Enter the number of productions.\n");
    scanf("%d", &n);
    printf("Enter the productions.\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%s", p[i]);
    }
    do
    {
        printf("Enter the symbol to find the first and follow.\n");
        scanf(" %c", c);
        first(c);
        printf("FIRST(%c) = {", c);
        for (int i = 0; i < k; i++)
        {
            if (i == k - 1)
            {
                printf("%c}\n", f[i]);
            }
            else
            {
                printf("%c,", f[i]);
            }
        }
        k = 0;
        strcpy(f, " ");
        printf("FOLLOW(%c) = {", c);
        for (int i = 0; i < k; i++)
        {
            if (i == k - 1)
            {
                printf("%c}\n", f[i]);
            }
            else
            {
                printf("%c,", f[i]);
            }
        }
        printf("Do you want to continue?(0/1)");
        scanf("%d", &ch);
    } while (ch == 1);
    return 0;
}

void first(char c)
{
    if (!isupper(c))
    {
        f[k++] = c;
    }
    for (int i = 0; i < n; i++)
    {
        if (p[i][0] == c)
        {
            if (p[i][2] == '$')
            {
                follow(p[i][0]);
            }
            else if (islower(p[i][2]))
            {
                f[k++] = p[i][2];
            }
            else
            {
                first(p[i][2]);
            }
        }
    }
}
void follow(char c)
{
    if (p[0][0] == c)
    {
        f[k++] = '$';
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 2; j < strlen(p[i]); j++)
        {
            if (p[i][j] == c)
            {
                if (p[i][j + 1] != '\0')
                {
                    first(p[i][j + 1]);
                }
                else if (p[i][j + 1] == '\0' && c != p[i][0])
                {
                    follow(p[i][0]);
                }
            }
        }
    }
}