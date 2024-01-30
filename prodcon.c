#include<stdio.h>
int mutex=1,in=0,out=0,full=0,empty,buffer[5],buffsize;
int wait(int s);
int signal(int s);
int producer();
int consumer();
int main()
{
    int o;
    printf("\nEnter buffer size:");
    scanf("%d",&buffsize);
    empty=buffsize;
    do
    {
        printf("\n1-Producer, 2-Consumer, 3-exit");
        scanf("%d",&o);
        switch(o)
        {
            case 1:producer();
            break;
            case 2:consumer();
            break;
            default:printf("\nIncorrect input");
        }
    }
    while(o!=3);

}
int wait(int s)
{
    while(s<0)
    {
        printf("\ncannot execute");
        exit(0);
    }
    return s--;
}
int signal(int s)
{
    s++;
    return s;
}
int producer()
{
    mutex=wait(mutex);
    empty=wait(empty);
    if((in+1)%buffsize==out)
    {
        printf("\nBuffer is full");
        full=signal(full);
        mutex=signal(mutex);
    }
    else
    {
        int next_pro;
        printf("\nEnter the item to be produced:");
        scanf("%d",&next_pro);
        buffer[in]=next_pro;
        in=(in+1)%buffsize;
        full=signal(full);
        mutex=signal(mutex);
        printf("\nProducer produces:%d",next_pro);
    }
}
int consumer()
{
    mutex=wait(mutex);
    full=wait(full);
    if(in==out)
    {
        printf("\nBuffer is empty");
        mutex=signal(mutex);
        empty=signal(empty);
    }
    else
    {
        int next_con;
        next_con=buffer[out];
        printf("Next consumed item:%d",next_con);
        out=(out+1)%buffsize;
        mutex=signal(mutex);
        empty=signal(empty);
    }
}
