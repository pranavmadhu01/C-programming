#include<stdio.h>
struct process{
  int id;
  int bt;
  int at;
  int tt;
  int rt;
  int ct;
  int wt;
};
int main()
{
  int timesplice,nprocess,sum=0,time=0;
  printf("\nEnter the timesplice for the processes.\n");
  scanf("%d",&timesplice);
  printf("\nEnter the number of processes.\n");
  scanf("%d",&nprocess);
  struct process a[nprocess];
  printf("\nEnter the processid arrivaltime and bursttime of the processes.\n");
  for (int i =0;i<nprocess;i++)
  {
    scanf("%d%d%d",&a[i].id,&a[i].at,&a[i].bt);
    a[i].rt = a[i].bt;
    sum=sum+a[i].rt;
  }
  while(sum>0)
  {
    for(int i=0;i<nprocess;i++)
    {
      if(a[i].rt>0)
      {
        if(a[i].rt<=timesplice)
        {
          time =time+a[i].rt;
          a[i].ct = time;
          a[i].rt =0;
        }
        else
        {
          a[i].rt = a[i].rt -timesplice;
          time =time+timesplice;
        }
        printf("\nThe process entered is %d and its remaining time is %d\n",a[i].id,a[i].rt);
      }
    }
    for(int i =0;i<nprocess;i++)
    {
      sum=0;
      sum+=a[i].rt;
    }
  }
  float tt_sum=0.0,wt_sum=0.0;
  for(int i=0;i<nprocess;i++)
  {
    a[i].tt = a[i].ct -a[i].at;
    tt_sum+=a[i].tt;
    a[i].wt = a[i].tt -a[i].bt;
    wt_sum+=a[i].wt;
  }
  printf("\nThe average turn around time is %f .\nThe average waiting time is %f.\n",(tt_sum/nprocess),(wt_sum/nprocess));
  return 0;
}