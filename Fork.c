#include<stdio.h>
 #include<unistd.h>
 int main() 
{
 int arr[100], n, id;
 int sumEven=0,sumOdd=0; 
 printf("Enter the limit: ");
 scanf("%d",&n); 
 int p=fork(); 
 if(p==0) 
 { 
 id=getpid();
 for(int i=0;i<n;i++)
 {
 if(i%2==0)
 {
 sumEven+=i;
 }
 }
 }
 printf("The sum of even numbers is :%d",sumEven);
 printf("\nThe child id is : %d\n\n",id);
 if(p!=0)
 {
 int id = getppid();
 for(int i=0;i<n;i++)
 {
 if(i%2!=0)
 {
 sumOdd+=i;
 }
 }
 printf("The sum of odd numbers is :%d",sumOdd);
 printf("\nThe parent id is : %d\n\n",id);
 }
return 0;
}
