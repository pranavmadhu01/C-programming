#include<stdio.h>
#include<stdlib.h>

int buffer_size,mutex=1,empty,full=0,x=0;

int signal(int s)
{
    return(++s);
}
int wait(int s)
{
    return(--s);
}

void producer()
{
   mutex=wait(mutex);
   empty = wait(empty);
   printf("%d",empty);
   full = signal(full);
   x++;
   printf("\nProducer produced the item %d.\n",x);
   mutex = signal(mutex);
}
void consumer()
{
   mutex=wait(mutex);
   empty = signal(empty);
   full = wait(full);
   printf("\nConsumer consumed %d\n",x);
   x--;
   mutex = signal(mutex);
}

void main(){
    int choice,buffer_size;
    printf("\nEnter the size of the buffer.\n");
    scanf("%d",&buffer_size);
    empty = buffer_size;
    while(1)
    {
        printf("\nEnter your choice \n1.Producer\n2.Consumer\n3.Exit.\n");
        scanf("%d",&choice);
        switch(choice)
        {
            //producer
            case 1:
            if(mutex!=0 && empty!=0)
            {
                producer();
            }
            else
            {
                printf("\nThere is no free space.\n");
            }
            break;
            //consumer
            case 2:
            if(mutex!=0 && full!=0)
            {
                consumer();
            }
            else
            {
                printf("\nThere is nothing to comsumee produce first.\n");
            }
            break;
            //exit the program
            case 3:
            exit (0);
        }
    }
}

