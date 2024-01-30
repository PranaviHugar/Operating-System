#include<stdio.h>
int n,p[10],bt[10],at[10],wt[10],tt[10],pri[10],sum=0,k=2,min,tbt=0,i,j;
float att=0.00,awt=0.00;
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
    printf("\nEnter priority:");
    for(i=1;i<=n;i++)
    {
        printf("\nProcess %d:",i);
        scanf("%d",&pri[i]);
    }
    for(i=1;i<=n;i++)
        for(j=i;j<=n;j++)
    {
        if(at[i]>at[j])
        {
            swap(&at[i],&at[j]);
            swap(&p[i],&p[j]);
            swap(&bt[i],&bt[j]);
            swap(&pri[i],&pri[j]);
        }
    }
    for(i=1;i<=n;i++)
    {
        tbt=tbt+bt[i];
        min=pri[k];
        for(j=k;j<=n;j++)
        {
            if(tbt>at[j] && pri[j]<min)
            {
                swap(&at[i],&at[j]);
                swap(&p[i],&p[j]);
                swap(&bt[i],&bt[j]);
                swap(&pri[i],&pri[j]);
            }
        }
        k++;
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
