#include <stdio.h>
int main()
{
  int bufferSize, rear = -1, front = -1, choice, countconsumer = 0, countproducer = 0;
  printf("Enter the buffer size\n");
  scanf("%d", &bufferSize);
  int cq[bufferSize];
  while (1)
  {
    printf("Enter whether you need to produce(1) or consume(2)\n");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
    {

      if (front == (rear + 1) % bufferSize)
      {
        printf("Buffer is full\n");
      }
      else
      {
        if (front == -1 && rear == -1)
        {
          front = 0;
          rear = 0;
        }
        else
        {
          rear = (rear + 1) % bufferSize;
        }
        countproducer++;
        printf("Producer produces the item %d\n", countproducer);
      }
      break;
    }
    case 2:
    {
      if (rear == -1 && front == -1)
      {
        printf("Buffer is empty\n");
      }
      else
      {
        if (front == rear)
        {
          front = -1;
          rear = -1;
        }
        else
        {
          front = front + 1 % bufferSize;
        }
        countconsumer++;
        printf("Consumer consumes item %d\n", countconsumer);
      }
    }
    }
  }
}