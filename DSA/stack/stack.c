#include<stdio.h>
#include<stdlib.h>
int main()
{
  int top=-1,maxsize,choice,item;
  printf("\nEnter the size of the stack.\n");
  scanf("%d",&maxsize);
  int stack[maxsize];
  while(1)
  {
    printf("\nEnter your choice \n1)Enter (1) to Push to stack\n2)Enter (2) to Pop from stack\n3)Enter (3) to Display stack elements\n4)Press any other key to exit.\n");
    scanf("%d",&choice);
    switch(choice)
    {
      //Push
      case 1:
      if(top == maxsize-1)
      {
        printf("\nStack is full no more elements can be inserted (Overflow).\n");

      }
      else
      {
        printf("\nEnter the item to be inserted in to the stack.\n");
        scanf("%d",&item);
        top =top+1;
        stack[top] =item;
      }
      break;

      //Pop
      case 2:
      if(top ==-1)
      {
        printf("No elements to pop out (Underflow).");
      }
      else
      {
        printf("\nThe item going to be popped is : %d.\n",stack[top]);
        top =top-1;
      }
      break;

      //Display

      case 3:
      if(top ==-1)
      {
        printf("No elements to pop out (Underflow).");
        
      }
      else
      {
        printf("\nThe stack is : \n");
        for(int i =0;i<=top;i++)
        {
          printf("%d",stack[i]);
        }
      }
      break;

      default :
      exit(0);

    }
  }

  return(0);
}