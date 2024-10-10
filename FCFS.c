#include<stdio.h>
void main()
{
int b[10], c[10], t[10], w[10], d, s, r, k=0, m=0, n, i;
printf("Enter the number of processes ");
scanf("%d",&n);
printf("The processes are\n");
for(i=0;i<n;i++)
{
printf("p%d\n",i);
}
printf("Enter the burst time\n");
for(i=0;i<n;i++)
{
printf("p%d:",i);
scanf("%d",&b[i]);
}
d=b[0];
c[0]=d;
for(i=1;i<n;i++)
{
c[i]=c[i-1]+b[i];
}
for(i=0;i<n;i++)
{
t[i]=c[i];
}
for(i=0;i<n;i++)
{
w[i]=t[i]-b[i];
}
printf("\n-------------------------------------\n");
printf("\nprocess\tburst time\twaitingtime\tturnaround time\t");
for(i=0;i<n;i++)
{
printf("\np%d \t%d \t%d \t %d \t",i,b[i],w[i],t[i]);
}
for(i=0;i<n;i++)
{
k=k+w[i];
}
s=k/n;
printf("\n\naverage waiting time=%d",s);
for(i=0;i<n;i++)
{
m=m+t[i];
}
r=m/n;
printf("\naverage turn around time=%d",r);
printf("\n\n-------------------------------------\n");
}
