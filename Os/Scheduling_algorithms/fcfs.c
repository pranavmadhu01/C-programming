#include<stdio.h>
struct process{
  int id;
  int at;
  int bt;
  int ct;
  int tt;
  int wt;
};
int main()
{
  int n_process;
  printf("\nEnter the number of processes.\n");
  scanf("%d",&n_process);
  struct process a[n_process];
  for(int i=0;i<n_process;i++)
  {
    printf("\nEnter the id,arrival_time and burst_time of the process %d.\n",i+1);
    scanf("%d%d%d",&a[i].id,&a[i].at,&a[i].bt);
  }
  a[0].ct = a[0].at+a[0].bt;
  for(int i=1;i<n_process;i++)
  {
    a[i].ct = a[i-1].ct+a[i].bt;
  }
  int sum_wt = 0;
  float avg_wt;
  for(int i =0;i<n_process;i++)
  {
    a[i].tt = a[i].ct-a[i].at;
    a[i].wt = a[i].tt-a[i].bt;
    sum_wt =sum_wt+a[i].wt;
  }
  avg_wt = sum_wt/n_process;
  printf("\nThe average waiting time is : %f\n",avg_wt);
  return 0;
}