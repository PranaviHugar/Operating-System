#include<stdio.h>
int n,i,p[10],bt[10],wt[10],tt[10],sum=0,awt=0,att=0;
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
    wt[1]=0;
    for(i=2;i<=n;i++)
    {
        sum=sum+bt[i-1];
        wt[i]=sum;
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
    printf("Process\t\tBurst time\t\tWaiting time\t\tTurnaround time\n");
    for(i=1;i<=n;i++)
    {
        printf("%d\t\t%d\t\t\t%d\t\t\t%d",p[i],bt[i],wt[i],tt[i]);
        printf("\n");
    }
    printf("\nAvg waiting time:%d",awt/n);
    printf("\nAvg turnaround time:%d",att/n);
}
