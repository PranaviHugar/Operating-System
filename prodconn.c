#include<stdio.h>
int buffer[5],buffsize,in=0,out=0,counter=0,mutex=1,empty,full=0;
int signal(int s);
int wait(int s);
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
         printf("\n1-Producer, 2-consumer, 3-exit");
         scanf("%d",&o);
         switch(o)
         {
             case 1:producer();
             break;
             case 2:consumer();
             break;
             default:printf("Incorrect");
         }
    }while(o!=3);
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
    if(counter==buffsize)
    {
        printf("\nBuffer is full");
        mutex=signal(mutex);
        full=signal(full);
    }
    else
    {
        int next_pro;
        printf("\nEnter the item to be produced:");
        scanf("%d",&next_pro);
        buffer[in]=next_pro;
        counter=counter+1;
        in=(in+1)%buffsize;
        full=signal(full);
        mutex=signal(mutex);
        printf("\nProducer produces %d",next_pro);
    }
}
int consumer()
{
    mutex=wait(mutex);
    full=wait(full);
    if(counter==0)
    {
        printf("\nBuffer is empty");
        mutex=signal(mutex);
        empty=signal(empty);
    }
    else
    {
        int next_con;
        next_con=buffer[out];
        printf("\nConsumer consumes:%d",next_con);
        out=(out+1)%buffsize;
        counter--;
        mutex=signal(mutex);
        empty=signal(empty);
    }
}
