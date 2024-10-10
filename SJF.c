#include<stdio.h>
void main()
{
int bt[20], p[20], wt[20], tat[20], i, j, n, total=0, pos, temp;
float avgwt, avgtat;
printf("\nEnter the number of process ");
scanf("%d",&n);
printf("\nEnter the burst time of each process ");
for(i=0;i<n;i++)
{
printf("\np%d : ",i+1);
scanf("%d",&bt[i]);
p[i]=i+1;
}
for(i=0;i<n;i++)
{
pos=i;
for(j=i+1;j<n;j++)
{
if(bt[j]<bt[pos])
pos=j;
}
temp=bt[i];
bt[i]=bt[pos];
bt[pos]=temp;
temp=p[i];
p[i]=p[pos];
p[pos]=temp;
}
for(i=2;i<n;i++);
{
wt[1]=0;
for(j=1;j<i;j++)
wt[j]+=bt[j-1];
}
for(i=0;i<n;i++)
{
total+=wt[i];
}
avgwt=(float)total/n;
total=0;
printf("\nprocess\tburst time\twaiting time\tturn around time");
for(i=0;i<n;i++)
{
tat[i]=bt[i]+wt[i];
total+=tat[i];
printf("\np%d \t%d \t%d \t\t%d",p[i],bt[i],wt[i],tat[i]);
}
avgtat=(float)total/n;
printf("\naverage turn around time : %f",avgtat);
printf("\naverage waiting time : %f",avgwt);
}
