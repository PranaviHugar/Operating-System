#include<stdio.h>
int n,i,p[10],bt[10],rembt[10],at[10],t=0,count=0,nextt,smallest,wt[10],tt[10];
float awt=0.00,att=0.00;
int main()
{
    printf("\nEnter no of process:");
    scanf("%d",&n);
    printf("\nEnter process:\n");
    for(i=1;i<=n;i++)
    {
        scanf("%d",&p[i]);
    }
    printf("\nEnter burst time:\n");
    for(i=1;i<=n;i++)
    {
        printf("P%d:",i);
        scanf("%d",&bt[i]);
        rembt[i]=bt[i];
    }
    printf("\nEnter arrival time:\n");
    for(i=1;i<=n;i++)
    {
        printf("P%d:",i);
        scanf("%d",&at[i]);
    }
    rembt[9]=999;
    for(t=0;count!=n;t++)
    {
        smallest=9;
        for(i=1;i<=n;i++)
        {
            if(at[i]<=t && rembt[i]>0 && rembt[i]<rembt[smallest])
            {
                smallest=i;
            }
        }
        rembt[smallest]--;
        if(rembt[smallest]==0)
        {
            nextt=t+1;
            wt[smallest]=nextt-bt[smallest]-at[smallest];
            tt[smallest]=wt[smallest]+bt[smallest];
            count++;
        }
    }
    for(i=1;i<=n;i++)
    {
        awt=awt+wt[i];
        att=att+tt[i];
    }
    printf("\n\nProcess\t\tBurst time\t\tArrival time\t\tWaiting time\t\tTurnaround time\n");
    for(i=1;i<=n;i++)
    {
        printf("%d\t\t%d\t\t\t%d\t\t\t%d\t\t\t%d",p[i],bt[i],at[i],wt[i],tt[i]);
        printf("\n");
    }
    printf("\nAvg waiting time:%f",awt/n);
    printf("\nAvg turnaround time:%f",att/n);
}
