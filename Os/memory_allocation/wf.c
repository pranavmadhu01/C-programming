#include<stdio.h>
struct spaces{
  int space;
  int visited;
};
int main()
{
  int no_partitions,no_process,process,flag =0;
  printf("\nEnter the no of partitions.\n");
  scanf("%d",&no_partitions);
  struct spaces a[no_partitions];
  printf("\nEnter the partitions.\n");
  for(int i=0;i<no_partitions;i++)
  {
    scanf("%d",&a[i].space);
    a[i].visited =0;
  }
  for(int i =0;i<no_partitions;i++)
  {
    int max =i;
    for(int j =i+1;j<no_partitions;j++)
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
  printf("\nEnter the no of process.\n");
  scanf("%d",&no_process);
  for(int i=0;i<no_process;i++)
  {
    printf("\nEnter the process.\n");
    scanf("%d",&process);
    for(int j =0;j<no_partitions;j++)
    {
      if(a[j].space>=process && a[j].visited!=1)
      {
        printf("\nThe procss entered in %d and the remainaing space is %d.\n",a[j].space,(a[j].space-process));
        a[j].visited =1;
        flag =0;
        break;
      }
      else
      {
        flag =1;
      }
    }
    if(flag ==1)
    {
      printf("\nThe process not entered.\n");
    }
  }
  return 0;
}