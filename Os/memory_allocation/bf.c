#include<stdio.h>
struct spaces{
  int space;
  int visited;
};
int main()
{
  int no_partitions,no_process,flag=0;
  printf("\nEnter the no of partitions.\n");
  scanf("%d",&no_partitions);
  struct spaces a[no_partitions];
  printf("\nEnter the partitions.\n");
  for(int i = 0;i<no_partitions;i++)
  {
    scanf("%d",&a[i].space);
    a[i].visited = 0;
  }
  printf("\nEnter the no of process.\n");
  scanf("%d",&no_process);
  int b[no_process];
  printf("\nEnter the process.\n");
  for(int i =0;i<no_process;i++)
  {
    scanf("%d",&b[i]);
  }
  for(int i =0;i<no_partitions;i++)
  {
    int max =i;
    for(int j =i;j<no_partitions;j++)
    {
      if(a[j].space>=a[max].space)
      {
        max =j;
      }
    }
    if(max !=i)
    {
      int temp = a[max].space;
      a[max].space = a[i].space;
      a[i].space = temp;
    }
  }
  for(int i =0;i<no_process;i++)
  {
    int max =i;
    for(int j =i;j<no_process;j++)
    {
      if(b[j]>=b[max])
      {
        max =j;
      }
    }
    if(max !=i)
    {
      int temp = b[max];
      b[max] = b[i];
      b[i] = temp;
    }
  }
  for(int i=0;i<no_process;i++)
  {
    for(int j =0;j<no_partitions;j++)
    {
      if(a[j].visited!=1 && a[j].space>=b[i])
      {
        printf("\nThe %d process entered the space %d and the remainaing space is %d.\n",b[i], a[j].space,(a[j].space-b[i]));
        a[j].visited =1;
        flag =0;
        break;
      }
      else
      {
        flag =1;
      }
    }
    if (flag ==1)
    {
      printf("\nThe process is not entered.\n");
    }
  }
  for(int i=0;i<no_partitions;i++)
  {
    if(a[i].visited !=1)
    {
      printf("\nThe partition %d is not at all occupied.\n",a[i].space);
    }
  }
}



