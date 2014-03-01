#include<iostream>
using namespace std;

struct Rule
{
 int st;
 int ed1;
 int ed2;
};
Rule rules[100];

int f[105][105][30];
int g[105][105];

int main()
{
 int n,i,l,st,k,j,c;
 char tr[4];
 char s[200];
 scanf("%d",&n);
 gets(tr);
 for(i=1;i<=n;i++)
 {
  gets(tr);
  rules[i].st = tr[0] - 'A';
  rules[i].ed1 = tr[1] - 'A';
  rules[i].ed2 = tr[2] - 'A';
 }
 gets(s);

 memset(f,0,sizeof(f));
 for(i=0;i<strlen(s);i++)
 {
  f[i][i][s[i]-'A'] = 1;
 }

 for(l=2;l<= strlen(s);l++)
 {
  for(st=0 ;st + l <= strlen(s) ;st++)
  {
   for(i = 1 ; i<=n ; i++)
   {
    for(k = st ; k< st +l -1;k++ )
    {
     f[st][st+l-1][rules[i].st] |= ( f[st][k][rules[i].ed1] * f[k+1][st+l-1][rules[i].ed2]);
    }
   }
  }
 }


 for(i = 0 ;i<strlen(s) ;i++)
  for(j = 0; j<strlen(s);j++)
   g[i][j] = 10000;
 
 
 for(l=1;l<= strlen(s);l++)
 {
  for(st=0 ;st + l <= strlen(s) ;st++)
  {
   if(f[st][st+l-1]['S'-'A'])
   {
    g[st][st+l-1] = 1;
   }
   else
   {
    for(k = st; k< st + l -1 ; k++)
    {
     if(g[st][k] + g[k+1][st+l-1] < g[st][st+l-1])  g[st][st+l-1] = g[st][k] + g[k+1][st+l-1];
    }
   }
  }
 }
 if(g[0][strlen(s)-1]>=1000) g[0][strlen(s)-1] = -1;
 printf("%d\n",g[0][strlen(s)-1]);
 return 0;
}
