#include<stdio.h>
int i,j,pno,bno,psize[10],bsize[10],alloc[10],flag[10],largest=0,tmp;
int main()
{
    printf("\nEnter no of processes:");
    scanf("%d",&pno);
    printf("\nEnter no of blocks:");
    scanf("%d",&bno);
    printf("\nEnter process size:");
    for(i=1;i<=pno;i++)
    {
        printf("P%d:",i);
        scanf("%d",&psize[i]);
    }
    printf("\nEnter block size:");
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
            if(flag[j]!=1)
            {
                tmp=bsize[j]-psize[j];
                if(tmp>=0)
                {
                    if(largest<tmp)
                    {
                        alloc[i]=j;
                        largest=tmp;
                    }
                }
            }
        }
        flag[alloc[i]]=1;
        largest=0;
    }
    printf("\nProcess no\t\tProcess size\t\tBlock no\t\tBlock size\n");
    for(i=1;i<=pno;i++)
    {
        printf("\nP%d\t\t\t%d\t",i,psize[i]);
        if(flag[i]==1)
        {
            printf("\t\tB%d\t\t\t%d",alloc[i],bsize[alloc[i]]);
        }
        else
        {
            printf("\tUnallocated");
        }
    }
}
