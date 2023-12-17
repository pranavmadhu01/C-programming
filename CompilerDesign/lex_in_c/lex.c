#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
void detect(char buffer[]);
bool operator(char buffer[]);
bool special(char buffer[]);
bool keyword(char buffer[]);
int main()
{
    FILE *ptr;
    char ch;
    char buffer[20];
    int idx = 0;
    ptr = fopen("input.txt", "r");
    while ((ch = fgetc(ptr)) != EOF)
    {
        if (ch == ' ' || ch == '\n')
        {
            buffer[idx] = '\0';
            detect(buffer);
            strcpy(buffer, "");
            idx = 0;
        }
        else
        {
            buffer[idx++] = ch;
        }
    }
    return 0;
}

void detect(char buffer[])
{
    if (operator(buffer))
    {
        printf("%s : Operator detected.\n", buffer);
    }
    else if (special(buffer))
    {
        printf("%s : Special Symbol detected.\n", buffer);
    }
    else if (keyword(buffer))
    {
        printf("%s : Keyword detected.\n", buffer);
    }
    else if (buffer[0] != '"' || !isdigit(buffer[0]))
    {
        printf("%s : Identifier detected.\n", buffer);
    }
    else
    {
        printf("%s : Literal detected.\n", buffer);
    }
}

bool operator(char buffer[])
{
    if (strcmp(buffer, "+") == 0 || strcmp(buffer, "-") == 0 || strcmp(buffer, "*") == 0 || strcmp(buffer, "/") == 0 || strcmp(buffer, "%") == 0 || strcmp(buffer, "=") == 0)
    {
        return true;
    }
    return false;
}

bool special(char buffer[])
{
    if (strcmp(buffer, ";") == 0 || strcmp(buffer, ":") == 0 || strcmp(buffer, "(") == 0 || strcmp(buffer, ")") == 0 || strcmp(buffer, "{") == 0 || strcmp(buffer, "}") == 0 || strcmp(buffer, "[") == 0 || strcmp(buffer, "]") == 0 || strcmp(buffer, ",") == 0)
    {
        return true;
    }
    return false;
}

bool keyword(char buffer[])
{
    if (strcmp(buffer, "int") == 0 || strcmp(buffer, "char") == 0 || strcmp(buffer, "float") == 0 || strcmp(buffer, "double") == 0 || strcmp(buffer, "bool") == 0 || strcmp(buffer, "if") == 0 || strcmp(buffer, "else") == 0 || strcmp(buffer, "for") == 0 || strcmp(buffer, "while") == 0 || strcmp(buffer, "break") == 0 || strcmp(buffer, "continue") == 0 || strcmp(buffer, "switch") == 0)
    {
        return true;
    }
    return false;
}
