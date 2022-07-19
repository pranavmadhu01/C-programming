#include<stdio.h>
int n,r,alloc[10][10],max[10][10],need[10][10],avail[10],work[10];
void banker()
{
    int i,j,k,count,count1=0,flag[10];
    for(i=0;i<n;i++)
    {
        flag[i]=0;
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<r;j++)
        {
            need[i][j]=max[i][j]-alloc[i][j];
        }
    }
    for(i=0;i<r;i++)
    {
        work[i]=avail[i];
    }
    while(count1<n)
    {
    for(i=0;i<n;i++)
    {
        int count=0;
        for(j=0;j<r;j++)
        {
            if((work[j]>=need[i][j]))
            {
                count++;
            }
        }
        if((count==r)&&(flag[i]!=1))
        {
            flag[i]=1;
            printf("P%d->",i);
            for(k=0;k<r;k++)
            {
                work[k]+=alloc[i][k];
            }
        }
    }
     count1++;
    } 
    printf("\n");
    for(i=0;i<n;i++)
    {
        if(flag[i]!=1)
        {
            printf("P%d cannot be executed\n",i);
        }
    }
}
int main()
{
    int i,j,ch,pno,req[10],availf,needf;
    printf("Enter no of process :\n");
    scanf("%d",&n);
    printf("Enter no of resource :\n");
    scanf("%d",&r);
    printf("Enter the allocation matrix :\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<r;j++)
        {
            scanf("%d",&alloc[i][j]);
        }
    }
    printf("Enter the max matrix :\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<r;j++)
        {
            scanf("%d",&max[i][j]);
        }
    }
    printf("Enter the available array :\n");
    for(i=0;i<r;i++)
    {
        scanf("%d",&avail[i]);
    }
    while(1)
    {
        printf("1.BANKER'S ALGO\n");
        printf("2.REQUEST\n");
        printf("3.EXIT\n");
        printf("Enter your choice :\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:banker();
                   break;
            case 2:printf("Enter the process no:\n");
                   scanf("%d",&pno);
                   printf("Enter the request of P%d\n",pno);
                   for(i=0;i<r;i++)
                   {
                       scanf("%d",&req[i]);
                   }
                   for(i=0;i<r;i++)
                   {
                       if(req[i]<=avail[i])
                       {
                           availf=1;
                       }
                       else
                       {
                           availf=0;
                           break;
                       }
                   }
                   for(i=0;i<r;i++)
                   {
                       if(req[i]<=need[pno][i])
                       {
                           needf=1;
                       }
                       else
                       {
                           needf=0;
                           break;
                       }
                       
                   }
                   if(availf==1&&needf==1)
                   {
                   for(i=0;i<r;i++)
                   {
                       alloc[pno][i]+=req[i];
                       avail[i]-=req[i];
                   }
                   banker();
                   }
                   break;
            case 3:return 0;           
        }
    }
}