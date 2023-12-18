#include<stdio.h>
#include<string.h>
char input[50],stack[50],action[50];
int k=0,i=0,len=0;
int check()
{
    if(stack[k-1]=='d' && stack[k-2]=='i')
    {
        stack[k-2]='E';
        stack[k-1]='\0';
        k=k-1;
        strcpy(action,"REDUCE");
        printf("%s\t%s\t%s E->id\n",stack,input,action);
        return 1;
    }
    else if(stack[k-1]=='E' && stack[k-2]=='+' && stack[k-3]=='E')
    {
        stack[k-3] = 'E';
        stack[k-2] = '\0';
        k = k-2;
        strcpy(action,"REDUCE");
        printf("%s\t%s\t%s E->E+E\n",stack,input,action);
        return 1;
    }
    else if(stack[k-1]=='E' && stack[k-2]=='*' && stack[k-3]=='E')
    {
        stack[k-3] = 'E';
        stack[k-2] = '\0';
        k = k-2;
        strcpy(action,"REDUCE");
        printf("%s\t%s\t%s E->E*E\n",stack,input,action);
        return 1;
    }
     else if(stack[k-1]==')' && stack[k-2]=='E' && stack[k-3]=='(')
    {
        stack[k-3] = 'E';
        stack[k-2] = '\0';
        k = k-2;
        strcpy(action,"REDUCE");
        printf("%s\t%s\t%s E->(E)\n",stack,input,action);
        return 1;
    }
    else
    {
        return 0;
    }
}
int main()
{
    printf("The grammer used to parse is as follows.\nE->E+E\nE->E*E\nE->(E)\nE->id\n");
    printf("Enter the string to parse.\n");
    scanf("%s",input);
    len = strlen(input);
    printf("STACK\tINPUT\tACTION\n");
    while (i<len || !(stack[0]=='E' && stack[1]=='\0'))
    {
        if (input[i]=='i' && input[i+1]=='d' && i+1<len)
        {
            stack[k] = input[i];
            stack[k+1] = input[i+1];
            stack[k+2] = '\0';
            input[i] = ' ';
            input[i+1] = ' ';
            k = k+2;
            i = i+2;
            strcpy(action,"SHIFT");
            printf("%s\t%s\t%s id\n",stack,input,action);
        }
        else
        {
            if(!check())
            {   
                strcpy(action,"SHIFT");
                stack[k]=input[i];
                char temp = input[i];
                stack[k+1]='\0';
                input[i]=' ';
                k++;
                i++;
                printf("%s\t%s\t%s %c\n",stack,input,action,temp);
                check();
            }
        }
    }
    return 0;
}
