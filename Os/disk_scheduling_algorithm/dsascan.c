#include<stdio.h>
struct trackstruct
{
  int value;
  int visited;
};
int main()
{
  int no_track,head_pos,max_track_pos,seek_time=0;
  printf("\nEnter the head position.\n");
  scanf("%d",&head_pos);
  printf("\nEnter the maximum track position.\n");
  scanf("%d",&max_track_pos);
  printf("\nEnter the number of tracks.\n");
  scanf("%d",&no_track);
  struct trackstruct track[no_track];
  printf("\nEnter the track sequence.\n");
  for(int i =0;i<no_track;i++)
  {
    scanf("%d",&track[i].value);
    track[i].visited = 0;
  }
  for(int i=0;i<no_track;i++)
  {
    int min =i;
    for(int j=i;j<no_track;j++)
    {
      if(track[min].value>track[j].value)
      {
        min =j;
      }
    }
    if(min!=i)
    {
      int temp = track[min].value;
      track[min].value = track[i].value;
      track[i].value = temp;
    }
  }
  for(int i = 0;i<no_track;i++)
  {
    if(head_pos<=track[i].value)
    {
      seek_time+=(track[i].value-head_pos);
      printf("\nThe track entered from %d to %d and the seek time is %d.\n",head_pos,track[i].value,(track[i].value-head_pos));
      head_pos = track[i].value;
      track[i].visited = 1;
    }
  }
  seek_time+=(max_track_pos-head_pos);
  printf("\nThe track entered from %d to %d and the seek time is %d.\n",head_pos,max_track_pos,(max_track_pos-head_pos));
  head_pos = max_track_pos;
  for(int i =no_track-1;i>=0;i--)
  {
    if(track[i].visited !=1)
    {
      seek_time+=(head_pos-track[i].value);
      printf("\nThe track entered is %d and the seek time is %d.\n",track[i].value,(head_pos-track[i].value));
      head_pos=track[i].value;
      track[i].visited =1;
    }
  }
  printf("\nThe seek time is %d.\n",seek_time);
  return 0;
}