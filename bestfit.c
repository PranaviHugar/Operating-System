#include<stdio.h>
int i,j,pno,bno,psize[10],bsize[10],alloc[10],flag[10],smallest=999,tmp;
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
                tmp=bsize[j]-psize[i];
                if(tmp>=0)
                {
                    if(smallest>tmp)
                    {
                        alloc[i]=j;
                        smallest=tmp;
                    }
                }
            }
        }
        flag[alloc[i]]=1;
        smallest=999;
    }
    printf("\n\nProcess no\t\tProcess size\t\tBlock no\t\tBlock size\n");
    for(i=1;i<=pno && alloc[i]!=0;i++)
    {
        printf("\nP%d\t\t\t%d\t\t\tB%d\t\t\t%d",i,psize[i],alloc[i],bsize[alloc[i]]);
    }

}
