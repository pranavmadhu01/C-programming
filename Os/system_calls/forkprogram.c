#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main()
{
  int flag, pid1, pid2;
  flag = fork();
  if (flag != 0)
  {
    if (flag == -1)
    {
      printf("Error while creating process\n");
      exit(1);
    }
    pid1 = getpid();
    printf("The process ID of the parent is %d\n", pid1);
  }
  else
  {
    pid2 = getpid();
    printf("The process ID of the child is %d\n", pid2);
  }
}