#include<stdio.h>
struct trackstruct
{
  int value;
  int visited;
};
int main()
{
  int head_pos,track_pos,no_track,seek_time=0;
  printf("\nEnter the head position.\n");
  scanf("%d",&head_pos);
  printf("\nEnter the maximum track position.\n");
  scanf("%d",&track_pos);
  printf("\nEnter the no of tracks.\n");
  scanf("%d",&no_track);
  struct trackstruct a[no_track];
  printf("\nEnter the track sequence.\n");
  for(int i =0;i<no_track;i++)
  {
    scanf("%d",&a[i].value);
    a[i].visited =0;
  }
  for(int i =0;i<no_track;i++)
  {
    if(head_pos<=a[i].value)
    {
      printf("\nThe head moves from %d to %d with seek time %d.\n",head_pos,a[i].value,(a[i].value-head_pos));
      a[i].visited =1;
      seek_time+=(a[i].value-head_pos);
      head_pos =a[i].value;
    }
    
  }
  printf("\nThe head moves from %d to maximum track position%d with seek time %d.\n",head_pos,track_pos,(track_pos-head_pos));
  seek_time+=(track_pos-head_pos);
  head_pos =0;
  seek_time+=track_pos;
  for(int i =0;i<no_track;i++)
  {
    if(head_pos<=a[i].value && a[i].visited!=1)
    {
      printf("\nThe head moves from %d to %d with seek time %d.\n",head_pos,a[i].value,(a[i].value-head_pos));
      a[i].visited =1;
      seek_time+=(a[i].value-head_pos);
      head_pos =a[i].value;
    }
    
  }
  printf("\nThe maximum seek time is %d.\n",seek_time);
  
return 0;
}
