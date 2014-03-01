#include<stdio.h>
#include<string.h>
int main()
{
int n,i;
int num[50],a[30];
scanf("%d",&n);
for(i=0;i<n;i++)
scanf("%d",&a[i]);
memset(num,0,sizeof(num));
for(i=0;i<n;i++)
{
int k=40-a[i];
while(k>=0)
{
if(num[k]>0)
num[k+a[i]]+=num[k];
k--;
}
num[a[i]]++;
}
printf("%d\n",num[40]);
return 0;
}
