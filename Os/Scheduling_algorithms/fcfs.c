#include<stdio.h>
struct process
{
  int id;
  int at;
  int bt;
  int ct;
  int tt;
  int wt;
};
int main()
{
  int no_process;
  float tt_sum=0.0,wt_sum=0.0;
  printf("\nEnter the no of processes.\n");
  scanf("%d",&no_process);
  struct process a[no_process];
  printf("\nEnter the process id,arrival time and burst time of the processes.\n");
  for(int i=0;i<no_process;i++)
  {
    scanf("%d %d %d",&a[i].id,&a[i].at,&a[i].bt);
  }
  for(int i =0;i<no_process;i++)
  {
    int min =i;
    for(int j =i;j<no_process;j++)
    {
      if(a[j].at<a[min].at)
      {
        min =j;
      }
    }
    if(min !=i)
    {
      int temp = a[min].at;
      a[min].at = a[i].at;
      a[i].at = temp;

      temp = a[min].id;
      a[min].id = a[i].id;
      a[i].id = temp;

      temp = a[min].bt;
      a[min].bt = a[i].bt;
      a[i].bt = temp;
    }
  }
  a[0].ct =a[0].bt;
  for(int i =1;i<no_process;i++)
  {
    a[i].ct = a[i-1].ct +a[i].bt;
  }
  for(int i =0;i<no_process;i++)
  {
    a[i].tt = a[i].ct -a[i].at;
    a[i].wt = a[i].tt -a[i].bt;
    tt_sum +=a[i].tt;
    wt_sum+=a[i].wt;
  }
  printf("\nID\t\tAT\t\tBT\t\tCT\t\tTT\t\tWT\n");
  for(int i=0;i<no_process;i++)
  {
    printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",a[i].id,a[i].at,a[i].bt,a[i].ct,a[i].tt,a[i].wt);
    
  }
  printf("The average Turn around time is :%f.\nThe average Waiting time is :%f",(tt_sum/no_process),(wt_sum/no_process));
  return 0;
}