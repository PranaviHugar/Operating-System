#include<stdio.h>
int i,j,n,m,p[10],max[10][10],alloc[10][10],avl[10],need[10][10],work[10],finish[10],count=0,s=0,seq[10],req[10],check1,check2,check3=0,check4=0,ps;
void input()
{
    printf("\nEnter no of process:");
    scanf("%d",&n);
    printf("\nEnter no of resources:");
    scanf("%d",&m);
    printf("\nEnter max matrix:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            scanf("%d",&max[i][j]);
        }
    }
    printf("\nEnter allocation matrix:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            scanf("%d",&alloc[i][j]);
        }
    }
    printf("\nEnter available:");
    for(j=0;j<m;j++)
    {
         scanf("%d",&avl[j]);
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            need[i][j]=max[i][j]-alloc[i][j];
        }
    }
    printf("\nNeed matrix:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            printf("%d",need[i][j]);
        }
        printf("\n");
    }

}
/*void safeseq()
{
    for(i=0;i<m;i++)
    {
        work[i]=avl[i];
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
            for(j=0;j<m;j++)
            {
                if((finish[i]==0) && (need[i][j]<=work[j]));
                {
                    check1++;
                }
                if(check1==m)
                {
                    for(j=0;j<m;j++)
                    {
                        work[j]=work[j]+alloc[i][j];
                        finish[i]=1;
                    }
                    seq[s]=i;
                    s++;
                    count++;
                }
            }
        }
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
        printf("\nSafe sequence exists");;
        for(i=0;i<n;i++)
        {
            printf("%d\t",seq[i]);
        }
    }
    else
    {
        printf("\nSafe sequence doesnt exist");
    }
}*/
void safeseq()
{
    for(i=0;i<m;i++)
    {
        work[i]=avl[i];
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
            for(j=0;j<m;j++)
            {
                if((finish[i]==0)&&(need[i][j]<=work[j]))
                {
                    check1++;
                }
                    if(check1==m)
                    {
                        for(j=0;j<m;j++)
                        {
                            work[j]=work[j]+alloc[i][j];
                            finish[i]=1;
                        }

                    seq[s]=i;
                    s++;
                    count++;
                }
            }
        }
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
            printf("\nSafe sequence exists:\t");
            for(i=0;i<n;i++)
            {
                printf("%d\t",seq[i]);
            }
        }
        else
        {
            printf("\nSafe sequence does not exist");
        }

}

void resourcereq()
{
    printf("\nEnter the resource that has requested:");
    scanf("%d",&ps);
    printf("\nEnter the request:");
    for(j=0;j<m;j++)
    {
        scanf("%d",&req[j]);
    }
    for(j=0;j<m;j++)
    {
        if(req[j]<=need[ps][j])
        {
            if(req[j]<=avl[j])
            {
                for(j=0;j<m;j++)
                {
                    alloc[ps][j]=alloc[ps][j]+req[j];
                    need[ps][j]=need[ps][j]-req[j];
                    avl[j]=avl[j]-req[j];
                }
            }
        }
        else
        {
            printf("\nRequest can not be granted");
            return;
        }
    }
    printf("\nRequest can be granted");
}
int main()
{
    input();
    safeseq();
    resourcereq();
    return 0;
}
