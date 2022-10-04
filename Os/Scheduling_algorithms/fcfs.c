#include <stdio.h>
struct process
{
  int at;
  int bt;
  int ct;
  int tt;
  int wt;
};
int main()
{
  int process_no;
  float avg_tt = 0.0, avg_wt = 0.0;
  printf("Enter the number of process \n");
  scanf("%d", &process_no);
  printf("Enter the arrival time and burst time of each processes\n");
  struct process a[process_no];
  for (int i = 0; i < process_no; i++)
  {
    scanf("%d %d", &a[i].at, &a[i].bt);
  }
  for (int i = 0; i < process_no; i++)
  {
    for (int j = 0; j < process_no - i - 1; j++)
    {
      if (a[j].at > a[j + 1].at)
      {
        struct process temp = a[j];
        a[j] = a[j + 1];
        a[j + 1] = temp;
      }
    }
  }
  a[0].ct = a[0].at + a[0].bt;
  a[0].tt = a[0].ct - a[0].at;
  a[0].wt = a[0].tt - a[0].bt;
  for (int i = 1; i < process_no; i++)
  {
    if (a[i].at <= a[i - 1].ct)
    {
      a[i].ct = a[i - 1].ct + a[i].bt;
    }
    else
    {
      a[i].ct = a[i].at + a[i].bt;
    }
    a[i].tt = a[i].ct - a[i].at;
    a[i].wt = a[i].tt - a[i].bt;
    avg_tt = avg_tt + a[i].tt;
    avg_wt = avg_wt + a[i].wt;
  }
  printf("The average turn around time and waiting tie is %f and %f\n", ((avg_tt + a[0].tt) / process_no), ((avg_wt + a[0].wt) / process_no));
}