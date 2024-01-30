#include<stdio.h>
int i,j,pno,bno,psize[10],bsize[10],alloc[10],flag[10];
int main()
{
    printf("\nEnter no of processes:");
    scanf("%d",&pno);
    printf("\nEnter no of blocks:");
    scanf("%d",&bno);
    printf("\nEnter process size:\n");
    for(i=1;i<=pno;i++)
    {
        printf("P%d:",i);
        scanf("%d",&psize[i]);
    }
    printf("\nEnter block size:\n");
    for(i=1;i<=bno;i++)
    {
        printf("P%d:",i);
        scanf("%d",&bsize[i]);
    }
    for(i=1;i<=bno;i++)
    {
        flag[i]=0;
        alloc[i]=-1;
    }
    for(i=1;i<=pno;i++)
    {
        for(j=1;j<=bno;j++)
        {
            if(flag[j]==0 && bsize[j]>=psize[i])
            {
                alloc[j]=i;
                flag[j]=1;
                break;
            }
        }
    }
    printf("\n\nBlock no\t\tBlock size\t\tProcess no\t\tProcess size\n");
    for(i=1;i<=bno;i++)
    {
        printf("\nB%d\t\t\t%d\t\t\t",i,bsize[i]);
        if(flag[i]==1)
        {
            printf("\tP%d\t\t\t%d",alloc[i],psize[alloc[i]]);
        }
        else
        {
            printf("\tUnallocated");
        }
    }
}
