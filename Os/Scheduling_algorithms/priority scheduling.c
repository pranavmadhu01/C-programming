#include<stdio.h>
struct process
{
  int id;
  int at;
  int bt;
  int p;
  int ct;
  int tt;
  int wt;
  int visited;
};
int  main()
{
  int no_process;
  printf("\nEnter the number of process.\n");
  scanf("%d",&no_process);
  struct process a[no_process];
  printf("Enter the ID,Arrival time, Burst time and Priority of each process");
  for(int i =0;i<no_process;i++)
  {
    scanf("%d %d %d %d",&a[i].id,&a[i].at,&a[i].bt,&a[i].p);
  }
  
}