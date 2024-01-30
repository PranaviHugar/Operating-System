#include<stdio.h>
int main()
{
    int pages[20],frame[3],n,fs,j=0,count=0,i,k,avl;
    printf("\nEnter no of reference strings:");
    scanf("%d",&n);
    printf("\nEnter reference pages:");
    for(i=1;i<=n;i++)
    {
        scanf("%d",&pages[i]);
    }
    printf("\nEnter frame size:");
    scanf("%d",&fs);
    for(i=1;i<=fs;i++)
    {
        frame[i]=-1;
    }
    printf("\nPages\tFrame\n");
    for(i=1;i<=n;i++)
    {
        avl=0;
        printf("%d",pages[i]);
        for(k=0;k<fs;k++)
        {
            if(frame[k]==pages[i])
            {
                avl=1;
            }
        }
        if(avl==0)
        {
            frame[j]=pages[i];
            j=(j+1)%fs;
            count++;
            for(k=0;k<fs;k++)
            {
                printf("\t%d",frame[k]);
            }
        }
        printf("\n");
    }
    printf("\nPage fault:%d",count);
}
