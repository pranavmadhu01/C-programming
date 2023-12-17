#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void input();
void constant();
void change(int i, int res);
void output();

struct expression
{
    char op[2], op1[5], op2[5], res[5];
    int flag;
} arr[10];
int n;

int main()
{
    input();
    constant();
    output();
    return 0;
}

void input()
{
    printf("Enter the number of expressions.\n");
    scanf("%d", &n);
    printf("Enter the expressions.\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%s", arr[i].op);
        scanf("%s", arr[i].op1);
        scanf("%s", arr[i].op2);
        scanf("%s", arr[i].res);
        arr[i].flag = 0;
    }
}

void constant()
{
    int op1, op2, res;
    char op;
    for (int i = 0; i < n; i++)
    {
        if ((isdigit(arr[i].op1[0]) && isdigit(arr[i].op2[0])) || strcmp(arr[i].op, "=") == 0)
        {
            op1 = atoi(arr[i].op1);
            op2 = atoi(arr[i].op2);
            op = arr[i].op[0];
            switch (op)
            {
            case '+':
                res = op1 + op2;
                break;
            case '-':
                res = op1 - op2;
                break;
            case '*':
                res = op1 * op2;
                break;
            case '/':
                res = op1 / op2;
                break;
            case '=':
                res = op1;
                break;
            }
            arr[i].flag = 1;
            change(i, res);
        }
    }
}

void change(int i, int res)
{
    printf("Hello\n");
    char res1[5];
    sprintf(res1, "%d", res);
    for (int j = i + 1; j < n; j++)
    {
        if (strcmp(arr[i].res, arr[j].op1) == 0)
        {
            strcpy(arr[j].op1, res1);
        }
        else if (strcmp(arr[i].res, arr[j].op2) == 0)
        {
            strcpy(arr[j].op2, res1);
        }
    }
}

void output()
{
    printf("The output is.\n");
    for (int i = 0; i < n; i++)
    {
        if (arr[i].flag == 0)
        {
            printf("\n%s %s %s %s", arr[i].op, arr[i].op1, arr[i].op2, arr[i].res);
        }
    }
}
