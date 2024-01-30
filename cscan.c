#include<stdio.h>
#include<math.h>
int main()
{
    int tdm=0,lv,hv,max,min,n,i,req[10],ch,d,j;
    printf("\nEnter total no of requests:");
    scanf("%d",&n);
    printf("\nEnter requests:");
    for(i=1;i<=n;i++)
    {
        scanf("%d",&req[i]);
    }
    printf("\nEnter current head position:");
    scanf("%d",&ch);
    printf("\nEnter lower value:");
    scanf("%d",&lv);
    printf("\nEnter higher value:");
    scanf("%d",&hv);
    printf("\nEnter the direction:- 1-left, 2-right:");
    scanf("%d",&d);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(req[i]<req[j])
            {
                min=req[i];
                req[i]=req[j];
                req[j]=min;
            }
        }
    }
    for(i=1;i<=n;i++)
    {
        if(ch>req[i])
        {
            p=req[i];
        }
        if(ch<req[i])
        {
            q=req[i];
        }
    }
    if(d==1)
    {
        tdm=abs(ch-lv)+abs(lv-hv)+abs(hv-q);
    }

    if(d==2)
    {
        tdm=abs(ch-hv)+abs(hv-lv)+abs(lv-p);
    }
}
