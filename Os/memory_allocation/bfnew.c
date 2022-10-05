#include <stdio.h>
struct memorys
{
  int value;
  int visited;
};
int main()
{
  int memory_block_no, process_no, process, mem_sum = 0, diff = 0, flag = -1;
  ;
  printf("Enter the numner of memory blocks\n");
  scanf("%d", &memory_block_no);
  struct memorys memory[memory_block_no];
  for (int i = 0; i < memory_block_no; i++)
  {
    scanf("%d", &memory[i].value);
    memory[i].visited = 0;
    mem_sum = mem_sum + memory[i].value;
  }
  printf("Enter the number of processes\n");
  scanf("%d", &process_no);
  for (int i = 0; i < process_no; i++)
  {
    printf("Enter the process %d\n", i + 1);
    scanf("%d", &process);
    for (int j = 0; j < memory_block_no; j++)
    {
      if (memory[j].visited != 1 && process <= memory[j].value)
      {
        diff = memory[j].value - process;
        if (diff < 0)
        {
          continue;
        }
        else
        {
          if (mem_sum > diff && diff >= 0)
          {
            mem_sum = diff;
            flag = j;
          }
        }
      }
    }
    if (flag != -1 && memory[flag].visited != 1)
    {
      printf("The process %d entered in the block %d\n", process, memory[flag].value);
      memory[flag].visited = 1;
    }
    else
    {
      printf("The process didnt enter the block\n");
    }
    mem_sum = 0;
    for (int k = 0; k < memory_block_no; k++)
    {
      mem_sum = mem_sum + memory[k].value;
    }
  }
}