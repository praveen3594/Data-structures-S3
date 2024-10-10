#include<stdio.h>
 int main()
{
 int i, j, n, time, remain, flag=0, time_quantum;
 int waiting_time=0,tat=0,at[10],bt[10],rt[10];
 printf("Enter Total Process:\t ");
 scanf("%d",&n);
 remain=n;
 for(i=0;i<n;i++)
 {
 printf("Enter Arrival Time and Burst Time for Process %d :",i+1);
 scanf("%d",&at[i]);
 scanf("%d",&bt[i]);
 rt[i]=bt[i];
 }
 printf("Enter Time Quantum:\t");
 scanf("%d",&time_quantum);
 printf("\n\nProcess\tTurnaround Time\tWaiting Time\n\n");
 
 for(time=0,i=0;remain!=0;)
 {
 if(rt[i]<=time_quantum && rt[i]>0)
 {
 time+=rt[i];
 rt[i]=0;
 flag=1;
 }
 else if(rt[i]>0)
 {
 rt[i]-=time_quantum;
 time+=time_quantum;
 }
 if(rt[i]==0 && flag==1)
 {
 remain--;
 
 printf("P[%d]\t\t%d\t\t%d\n",i+1,time-at[i],time-at[i]-bt[i]);
 waiting_time+=time-at[i]-bt[i];
 tat+=time-at[i];
 flag=0;
 }
 if(i==n-1)
 i=0;
 else if(at[i+1]<=time)
 i++;
 else
 i=0;
 }
 printf("\nAverage Waiting Time= %f\n",waiting_time*1.0/n);
 printf("Avg Turnaround Time = %f",tat*1.0/n);
 
 return 0; 
}
