#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<queue>
using namespace std;

struct Road
{
	int st,ed,weigh;
 	bool operator < (const Road & a) const
	{
		if(st==a.st)
   		{
    		if(ed==a.ed) return weigh<a.weigh;
    			return ed<a.ed;
	   }
   return st<a.st;
 }
};
Road roadsS[1000005];
int stposS[1000005];
int n,m;
int dis[1000005];
bool isIn[1000005];
void spfa(Road roads[],int stpos[],int st)
{
 for(int i=1;i<=n;i++)
 {
   dis[i]=10000000;
   isIn[i]=false;
 }
 isIn[st]=true;
 dis[st]=0;
 queue<int> myqueue;
 myqueue.push(st);
 int temp;
 int stb;
 while(!myqueue.empty())
 {
   temp=myqueue.front();
   isIn[temp]=false;
   myqueue.pop();
   for(stb=stpos[temp-1];stb<m && roads[stb].st==temp;stb++)
   {
    int v=roads[stb].ed;
    int u=temp;
    if(dis[v] > dis[u]+roads[stb].weigh)
    {
     dis[v] =  dis[u]+roads[stb].weigh;
     if(!isIn[v])
     {
      isIn[v]=true;myqueue.push(v);
     }
    }
   }
 }
}

int dis1_n[1000005];
int disn_1[1000005];
int main(){
	int st,ed,weigh;
	int result;
	memset(stposS,0,sizeof(stposS));
 	scanf("%d%d",&n,&m);
 	for(int i=0;i<m;i++){
	   scanf("%d%d%d",&st,&ed,&weigh);
	   stposS[st]++;
	   stposS[ed]++;
   	   roadsS[i].st=st;roadsS[i].ed=ed;roadsS[i].weigh=weigh;
   	   roadsS[i+m].st=ed;roadsS[i+m].ed=st;roadsS[i+m].weigh=weigh;
 	}
 	m = m*2;
	stposS[0]=0;
 	for(int i=1;i<=n;i++) {stposS[i]+=stposS[i-1];}
 	sort(roadsS,roadsS+m);
 	result=0;
 	spfa(roadsS,stposS,1);
 	for(int i=1;i<=n;i++)  
	 	dis1_n[i] = dis[i];
 	spfa(roadsS,stposS,n);
 	for(int i=1;i<=n;i++)  
	 	disn_1[i] = dis[i];
 	int minRoad = dis1_n[n];
 	result = 10000000;
 	for(int i=0;i<m;i++){
   		result = min(result,minRoad + 2*roadsS[i].weigh);
   		int temp = dis1_n[roadsS[i].st] + disn_1[roadsS[i].ed] + roadsS[i].weigh;
   		result = min(result,temp);
 }
 
 printf("%d\n",result);
 return 0;
}
