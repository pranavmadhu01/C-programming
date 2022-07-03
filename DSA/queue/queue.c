#include<stdio.h>
#include<stdlib.h>
int main()
{
  int maxsize,choice,front =-1,rear =-1,item;
  printf("\nEnter the size of the queue\n");
  scanf("%d",&maxsize);
  int queue[maxsize];
  while(1)
  {
    printf("\nEnter your choice\n1)press (1) to Enqueue\n2)press (2) to Dequeue\n3)press (3) to Display\n4)Press any other key to exit.\n");
    scanf("%d",&choice);
    switch(choice)
    {

      //Enqueue

      case 1:
      if(rear ==maxsize-1)
      {
        printf("\nThere is no space in the queue (Overflow).\n");
      }
      else
      {
        printf("\nEnter the item to be inserted.\n");
        scanf("%d",&item);
        if(front ==-1)
        {
          front =0;
          rear =0;
        }
        else
        {
          rear = rear+1;
        }
        queue[rear]=item;
      }
      break;

      //Dequeue

      case 2:
      if(front ==-1 || front >rear)
      {
        printf("Nothing to dequeue (Underflow).");
      }
      else
      {
        printf("\nThe item going to be dequeued is : %d.\n",queue[front]);
        if(front == rear)
        {
          front =-1;
          rear=-1;
        }
        else
        {
          front =front+1;
        }
      }
      break;

      //Display

      case 3:
      if(front ==-1 || front >rear)
      {
        printf("Nothing to display (Underflow).");
      }
      else
      {
        printf("\nThe queue is :\n");
        for(int i = front;i <=rear;i++)
        {
          printf("%d",queue[i]);
        }
      }
      break;

      //Exiting program for any other key press

      default :
      exit(0);
    }
  }
  return(0);
}