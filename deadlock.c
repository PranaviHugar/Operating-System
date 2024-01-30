#include<stdio.h>
int n,m,i,j,req[10][10],alloc[10][10],p[10],work[10],avl[10],finish[10],s=0,check1,check2,count=0,seq[10];
int main()
{
    input();
    deadlock();
}
int input()
{
    printf("\nEnter no of process");
    scanf("%d",&n);
    printf("\nEnter no of resource");
    scanf("%d",&m);
    printf("\nEnter request matrix:");
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            scanf("%d",&req[i][j]);
        }
    }
    printf("\nEnter alloc:");
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            scanf("%d",&alloc[i][j]);
        }
    }
    printf("\nEnter avl:");
    for(i=0;i<m;i++)
    {
        scanf("%d",&avl);
    }



}
void deadlock()
{
    count=0,check1=0,check2=0,s=0;
    for(i=0;i<m;i++)
    {
        work[j]=avl[j];
    }
    for(i=0;i<n;i++)
    {
        finish[i]=0;
    }
    while(count!=n)
    {
        for(i=0;i<n;i++)
        {
            check1=0;
            if(finish[i])continue;
            for(j=0;j<m;j++)
            {
                if(req[i][j]<=work[j])
                {
                    check1++;
                }
                if(check1==m)
                {
                    for(j=0;j<m;j++)
                    {
                        work[j]=work[j]+alloc[i][j];
                    }
                    finish[i]=1;
                    seq[s]=i;
                    s++;
                }
            }
        }
        count++;
    }
    for(i=0;i<n;i++)
    {
        if(finish[i]==1)
        {
            check2++;
        }
    }
    if(check2==n)
    {
        printf("\nSafe seq exists");
        for(i=0;i<n;i++)
        {
            printf("%d\t",seq[i]);
        }
    }
    else
    {
        printf("safe seq dont exists");
    }
}
