#include<stdio.h>
#include<math.h>
int main()
{
    int tdm=0,ch,req[10],n,i;
    printf("\nEnter total no of requests:");
    scanf("%d",&n);
    printf("\nEnter requests:");
    for(i=1;i<=n;i++)
    {
        scanf("%d",&req[i]);
    }
    printf("\nEnter current head position:");
    scanf("%d",&ch);
    for(i=1;i<=n;i++)
    {
        tdm=tdm+abs(ch-req[i]);
        ch=req[i];
    }
    printf("\nTotal disk movement:%d",tdm);
}
