#include<stdio.h>
int writing=0;
int readercount=0;
int writercount=0;
void read()
{ readercount++;
 printf("\nReader(%d)is reading....\n",readercount);}
void write()
{ writing=1;
 writercount++;
 printf("\nWriter(%d)is writing....\n",writercount);}
int main()
{ int choice;
 do
 { printf("\n\nSelect operation....\n1)Read\n2)Write\n3)Delete last reader\n4)Delete last writer\
n5)Exit");
 printf("\n...\nEnter your choice: ");
 scanf("%d",&choice);
 if(choice==1)
 { if(writing==0)
 { read(); }
 else
 { printf("\nCannot read, A writer is currently writing...\n"); } }
 else if(choice==2)
 { write(); }
 else if(choice==3)
 { printf("\nA reader(%d)is removed\n,",readercount);
 readercount--; }
else if(choice==4)
 {
 printf("\nA writer(%d)is removed\n",writercount);
 writercount--;
 if(writercount==0)
 {
 printf("\nCurrently none is writing....\n");
 writing=0;
 } }
 else if(choice==5)
 { printf("\n!!!ExItInG!!!\n\n"); }
 }while(choice!=5);
}
