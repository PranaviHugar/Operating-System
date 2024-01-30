#include<stdio.h>
#include<math.h>
int main()
{
    int tdm=0,count=0,dist,min,index,ch,req[10],n,i;
    printf("\nEnter total no of requests:");
    scanf("%d",&n);
    printf("\nEnter requests:");
    for(i=1;i<=n;i++)
    {
        scanf("%d",&req[i]);
    }
    printf("\nEnter current head position:");
    scanf("%d",&ch);
    while(count!=n)
    {
        min=999;
        for(i=1;i<=n;i++)
        {
            dist=abs(ch-req[i]);
            if(min>dist)
            {
                min=dist;
                index=i;
            }
        }
        tdm=tdm+min;
        ch=req[index];
        req[index]=9999;
        count++;
    }
    printf("\nTDM:%d",tdm);
}
