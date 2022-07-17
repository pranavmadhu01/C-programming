#include<stdio.h>
struct spaces{
  int space;
  int visited;
};
int main()
{
  int no_space,no_process,process,flag=0;
  printf("\nEnter the no of partitions.\n");
  scanf("%d",&no_space);
  struct spaces a[no_space];
  printf("\nEnter the partitions.\n");
  for(int i = 0;i<no_space;i++)
  {
    scanf("%d",&a[i].space);
    a[i].visited = 0;
  }
  printf("\nEnter the no of process.\n");
  scanf("%d",&no_process);
  for(int i=0;i<no_process;i++)
  {
    printf("\nEnter the process value.\n");
    scanf("%d",&process);
    for(int j =0;j<no_space;j++)
    {
      if(a[j].visited!=1 && a[j].space>=process)
      {
        printf("\nThe process entered the space %d and the remainaing space is %d.\n",a[j].space,(a[j].space-process));
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
  return 0;
}