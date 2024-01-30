#include<stdio.h>
int n,i,p[10],bt[10],at[10],pri[10],rbt[10],wt[10],tt[10],smallest,t,nextt,count=0;
float awt=0.00,att=0.00;
int main()
{
    printf("\nEnter no of process:");
    scanf("%d",&n);
    printf("\nEnter process:");
    for(i=1;i<=n;i++)
    {
        scanf("%d",&p[i]);
    }
    printf("\nEnter burst time:\n");
    for(i=1;i<=n;i++)
    {
        printf("P%d:",i);
        scanf("%d",&bt[i]);
        rbt[i]=bt[i];
    }
    printf("\nEnter arrival time:\n");
    for(i=1;i<=n;i++)
    {
        printf("P%d:",i);
        scanf("%d",&at[i]);
    }
    printf("\nEnter priority:\n");
    for(i=1;i<=n;i++)
    {
        printf("P%d:",i);
        scanf("%d",&pri[i]);
    }
    pri[9]=999;
    for(t=0;count!=n;t++)
    {
        smallest=9;
        for(i=1;i<=n;i++)
        {
            if(at[i]<=t && rbt[i]>0 && pri[i]<pri[smallest])
            {
                smallest=i;
            }
        }
        rbt[smallest]--;
        if(rbt[smallest]==0)
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
    printf("\n\nProcess\t\tBurst time\t\tArrival time\t\tPriority\t\tWaiting time\t\tTurnaround time\n");
    for(i=1;i<=n;i++)
    {
        printf("%d\t\t%d\t\t%d\t\t\t%d\t\t\t%d\t\t\t%d",p[i],bt[i],at[i],pri[i],wt[i],tt[i]);
        printf("\n");
    }
    printf("\nAverage waiting time:%f",awt/n);
    printf("\nAverage turnaround time:%f",att/n);

}
