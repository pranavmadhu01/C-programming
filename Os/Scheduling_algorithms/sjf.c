#include<stdio.h>
struct process{
  int id;
  int at;
  int bt;
  int ct;
  int wt;
  int tt;
  int visited;
};
struct stack
{
  int id;
  int bt;
};
int main()
{
  int no_process,min_index,visited_sum=0,top=-1,post_completion_time;
  printf("\nEnter the no of process.\n");
  scanf("%d",&no_process);
  struct process a[no_process];
  struct stack b[no_process];
  printf("\nEnter the process ID, arrival timr and burst time.\n");
  for(int i =0;i<no_process;i++)
  {
    scanf("%d %d %d",&a[i].id,&a[i].at,&a[i].bt);
    a[i].visited =0;
  }
  for(int i =0;i<no_process;i++)
  {
    int min =i;
    for(int j=i;j<no_process;j++)
    {
      if(a[min].at>=a[j].at)
      {
        min =j;
      }
    }
    if(min !=i)
    {
      min_index =min;
    }
  }
  a[min_index].ct = a[min_index].bt;
  post_completion_time = a[min_index].ct;
  a[min_index].tt = a[min_index].ct-a[min_index].at;
  a[min_index].wt = a[min_index].tt-a[min_index].bt;
  a[min_index].visited =1;
  while(visited_sum<=no_process)
  {
    for(int i = 0;i<no_process;i++)
    {
      if(a[min_index].ct>=a[i].at && a[i].visited!=1)
      {
        printf("\nThe process %d has arrived to the queue.\n",a[i].id);
        top++;
        b[top].bt = a[i].bt;
        b[top].id = i;
      }
    }
    for(int i =0;i<=top;i++)
    {
      int max =i;
      for(int j=i;j<=top;j++)
      {
        if(b[max].bt<=b[j].bt)
        {
          max =j;
        }
      }
      if(max !=i)
      {
        int temp = b[max].bt;
        b[max].bt = b[i].bt;
        b[i].bt = temp;

        temp = b[max].id;
        b[max].id = b[i].id;
        b[i].id = temp;
      }
    }
    a[b[top].id].ct = post_completion_time +a[b[top].id].bt;
    post_completion_time = a[b[top].id].ct;
    a[b[top].id].tt = a[b[top].id].ct -a[b[top].id].at;
    a[b[top].id].wt = a[b[top].id].tt -a[b[top].id].bt;
    min_index = b[top].id;
    a[b[top].id].visited = 1;
    top --;
    for(int i=0;i<no_process;i++)
    {
      if(a[i].visited==1)
      {
        visited_sum+=a[i].visited;
      }
    }
  }
  float tt_sum =0,wt_sum =0;
  float tt_avg =0,wt_avg =0;
  printf("ID\t\tAt\t\tBt\t\tCt\t\tTt\t\tWt\n");
  for(int i=0;i<no_process;i++)
  {
    printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",a[i].id,a[i].at,a[i].bt,a[i].ct,a[i].tt,a[i].wt);
    tt_sum += a[i].tt;
    wt_sum += a[i].wt;
  }
  printf("\nThe average turn around time is :%f.\n\nThe average waiting time is:%f.",(tt_sum/no_process),(wt_sum/no_process));
  return 0;
}