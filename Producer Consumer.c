#include<stdio.h>
#include<stdlib.h>
int mutex=1,full=0,buf=0,item=0;
int wait(int s)
{ return(--s); }
int signal(int s)
{ return(++s); }
 void producer()
{ mutex=wait(mutex);
 full=signal(full);
 buf=wait(buf);
 item++;
 printf("\nProducer produced item %d\n",item);
 mutex=signal(mutex);}
void consumer()
{ mutex=wait(mutex);
 full=wait(full);
 buf=signal(buf);
 printf("\nConsumer consumed item %d\n",item);
 item--;
 mutex=signal(mutex);}
void main()
{ int ch;
 printf("Enter buffer size: ");
 scanf("%d",&buf);
 while(1)
 { printf("\nMENU:\n1.ProduceR\n2.ConsumeR\n3.ExiT\nENTER YOUR CHOICE:");
 scanf("%d",&ch);
 switch(ch)
 { case 1: if((mutex==1)&&(buf!=0))
 producer();
 else
 printf("\nBuffer is full\n");
 break;
case 2: if((mutex==1)&&(full!=0))
 consumer();
 else
 printf("\nBuffer is empty\n");
 break;
case 3: printf("\nTerminated!!!!\n\n");
 exit(0);
 break;
 default: printf("invalid"); } }
 }
