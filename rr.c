#include<stdio.h>
#include<stdbool.h>
int n,i,p[10],bt[10],rembt[10],wt[10],tt[10],ts,t=0;
float awt=0.00,att=0.00;
bool c;
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

    printf("\nEnter time slice:");
    scanf("%d",&ts);
    while(true)
    {
        c=true;
        for(i=1;i<=n;i++)
        {
            if(rembt[i]>0)
            {
                c=false;
                if(rembt[i]>ts)
                {
                    t=t+ts;
                    rembt[i]=rembt[i]-ts;
                }
                else
                {
                    t=t+rembt[i];
                    rembt[i]=0;
                    wt[i]=t-bt[i];
                }
            }
        }
        if(c==true)
        {
            break;
        }
    }
    for(i=1;i<=n;i++)
    {
        awt=awt+wt[i];
        tt[i]=wt[i]+bt[i];
        att=att+tt[i];
    }
    printf("\n\nProcess\t\tBurst time\t\tWaiting time\t\tTurnaround time\n");
    for(i=1;i<=n;i++)
    {
        printf("%d\t\t%d\t\t\t%d\t\t\t%d",p[i],bt[i],wt[i],tt[i]);
        printf("\n");
    }
    printf("\nAvg waiting time:%f",awt/n);
    printf("\nAvg turnaround time:%f",att/n);
}
