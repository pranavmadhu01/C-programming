#include <stdio.h>
struct process
{
  int at;
  int bt;
  int ct;
  int tt;
  int wt;
  int visited;
};
int mininumBt(int a[], int n)
{
  for (int i = 0; i < n; i++)
  {
    printf("%d ", a[i]);
  }
  printf("\n");
  int location = 0;
  for (int i = 0; i < n; i++)
  {
    if (a[i] != -1)
    {
      location = i;
      break;
    }
  }
  for (int i = 0; i < n; i++)
  {
    if (a[i] < a[location] && (a[i] != -1 && a[location] != -1))
    {
      location = i;
    }
  }
  return (location);
}
int main()
{
  int process_no;
  float avg_tt = 0.0, avg_wt = 0.0;
  printf("Enter the number of process \n");
  scanf("%d", &process_no);
  printf("Enter the arrival time and burst time of each processes\n");
  struct process a[process_no];
  int a_bt[process_no];
  for (int i = 0; i < process_no; i++)
  {
    scanf("%d %d", &a[i].at, &a[i].bt);
    a_bt[i] = -1;
    a[i].visited = 0;
  }
  for (int i = 0; i < process_no; i++)
  {
    for (int j = 0; j < process_no - i - 1; j++)
    {
      if (a[j].at >= a[j + 1].at)
      {
        if (a[j].at > a[j + 1].at)
        {
          struct process temp = a[j];
          a[j] = a[j + 1];
          a[j + 1] = temp;
        }
        else
        {
          if (a[j].bt > a[j + 1].bt)
          {
            struct process temp = a[j];
            a[j] = a[j + 1];
            a[j + 1] = temp;
          }
        }
      }
    }
  }
  printf("\n");
  for (int i = 0; i < process_no; i++)
  {
    printf("%d", a[i].bt);
  }
  printf("\n");
  a[0].ct = a[0].at + a[0].bt;
  a[0].tt = a[0].ct - a[0].at;
  a[0].wt = a[0].tt - a[0].bt;
  a[0].visited = 1;
  int ct = a[0].ct;
  for (int i = 1; i < process_no; i++)
  {
    for (int j = 1; j < process_no; j++)
    {
      if (a[j].at <= ct && a[j].visited != 1)
      {
        a_bt[j] = a[j].bt;
      }
    }
    int min_index = mininumBt(a_bt, process_no);
    printf("min_index = %d\n", min_index);
    a[min_index].ct = ct + a[min_index].bt;
    a[min_index].tt = a[min_index].ct - a[min_index].at;
    a[min_index].wt = a[min_index].tt - a[min_index].bt;
    a[min_index].visited = 1;
    a_bt[min_index] = -1;
    avg_tt = avg_tt + a[min_index].tt;
    avg_wt = avg_wt + a[min_index].wt;
    ct = a[min_index].ct;
  }

  printf("The average turn around time and waiting time is %f and %f\n", ((avg_tt + a[0].tt) / process_no), ((avg_wt + a[0].wt) / process_no));
}