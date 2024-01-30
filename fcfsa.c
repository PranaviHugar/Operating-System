#include<stdio.h>
int n,i,j,p[10],bt[10],wt[10],at[10],tt[10],sum=0;
float awt=0.0,att=0.0;
int main()
{
    printf("Enter no of process:");
    scanf("%d",&n);
    printf("\nEnter processes:");
    for(i=1;i<=n;i++)
    {
        scanf("%d",&p[i]);
    }
    printf("\nEnter burst time:");
    for(i=1;i<=n;i++)
    {
        printf("\nProcess %d:",i);
        scanf("%d",&bt[i]);
    }
    printf("\nEnter arrival time:");
    for(i=1;i<=n;i++)
    {
        printf("\nProcess %d:",i);
        scanf("%d",&at[i]);
    }
    for(i=1;i<=n;i++)
        for(j=i;j<=n;j++)
        {
            if(at[i]>at[j])
            {
                swap(&at[i],&at[j]);
                swap(&bt[i],&bt[j]);
                swap(&p[i],&p[j]);
            }
        }
    wt[1]=0;
    for(i=2;i<=n;i++)
    {
        sum=sum+bt[i-1];
        wt[i]=sum-at[i];
    }
     for(i=1;i<=n;i++)
    {
        tt[i]=wt[i]+bt[i];
    }
    for(i=1;i<=n;i++)
    {
        awt=awt+wt[i];
        att=att+tt[i];
    }
    printf("Process\t\tBurst time\t\tArrival time\t\tWaiting time\t\tTurnaround time\n");
    for(i=1;i<=n;i++)
    {
        printf("P%d\t\t%d\t\t\t%d\t\t\t%d\t\t\t%d",p[i],bt[i],at[i],wt[i],tt[i]);
        printf("\n");
    }
    printf("\nAvg waiting time:%f",awt/n);
    printf("\nAvg turnaround time:%f",att/n);
}
void swap(int *x,int *y)
{

    int tmp;
    tmp=*x;
    *x=*y;
    *y=tmp;
}
