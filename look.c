#include<stdio.h>
#include<math.h>
int main()
{
    int tdm=0,lv,hv,max,min,n,i,req[10],ch,d;
    printf("\nEnter total no of requests:");
    scanf("%d",&n);
    printf("\nEnter requests:");
    for(i=1;i<=n;i++)
    {
        scanf("%d",&req[i]);
    }
    printf("\nEnter current head position:");
    scanf("%d",&ch);
    min=req[1];
    max=req[1];
    for(i=2;i<=n;i++)
    {
        if(min>req[i])
        {
            min=req[i];
        }
        if(max<req[i])
        {
            max=req[i];
        }
    }
     printf("\nEnter the direction:- 1-left, 2-right:");
    scanf("%d",&d);
    if(d==1)
    {
        tdm=abs(ch-min)+abs(min-max);
    }
    if(d==2)
    {
        tdm=abs(ch-max)+abs(max-min);
    }
    printf("TDM:%d",tdm);
}
