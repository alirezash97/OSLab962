#include <stdio.h>
#include <stdlib.h>

//Queue reversing.........................
void ReverseAnArray(int Arr[],int start,int end)
{
    while (start<end) {
      int temp = Arr[start];
      Arr[start] = Arr[end];
      Arr[end] = temp;
      start++;
      end--;
    }
}
int main()
{
  int CurrentHeadPosition,MaxNumTracks,QueueElements;

  printf("Enter the current head position:");
  scanf("%d",&CurrentHeadPosition);
  printf("\nEnter the Maximum number of the tracks:");
  scanf("%d",&MaxNumTracks);
  printf("\nEnter number of elements into the queue:");
  scanf("%d",&QueueElements);
  printf("\nEnter Disk tracks elements:\n");

  int queue[QueueElements],count1=0,count2=0,seekTime=0,TotalSeekTime=0;
  while (count1<QueueElements)
  {
    int value;
    scanf("%d",&value);

    if(value>0 && value<=MaxNumTracks)
      queue[count1]= value;
    count1++;
  }

  ReverseAnArray(queue,0,QueueElements-1);

  while(count2<QueueElements)
  {
    seekTime = abs(CurrentHeadPosition - queue[count2]);
    printf("%d--(%d)-->%d\n",CurrentHeadPosition,seekTime,queue[count2]);
    CurrentHeadPosition = queue[count2];
    count2++;
    TotalSeekTime +=seekTime;
  }
  printf("Total Seek time is equal to:%d\n",TotalSeekTime);
  printf("Average Seek time:%.2f\n",(float)TotalSeekTime/QueueElements);

}
