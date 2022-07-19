#include <stdio.h>
int main()
{
    int pno,fno,page[20],frame[20],i,j,flag=0,count=0;
    printf("Enter the no of pages :\n");
    scanf("%d",&pno);
    printf("Enter the pages :\n");
    for(i=0;i<pno;i++)
    {
        scanf("%d",&page[i]);
    }
    printf("Enter the no of frames :\n");
    scanf("%d",&fno);
    int k=0;
    for(i=0;i<pno;i++)
    {
        flag=0;
        for(j=0;j<fno;j++)
        {
            if(page[i]==frame[j])
            {
                printf("\nThere is a page hit.%d already exist\n",page[i]);
                flag=1;
            }
        }
        if(flag==0)
        {
            frame[k]=page[i];
            printf("\nThere is a page fault.page %d enteres frame %d\n",page[i],k);
            k=(k+1)%fno;
            count++;
        }
    }
    printf("page faults :%d\n",count);
    return 0;
}