//A bug's life并查集的典型应用 
//代码非常简洁，含义十分深刻！！！妙！！！ 
#include<stdio.h>
#include<algorithm>
#include<string.h>
struct{
  int pre;
  int rank;
 }bug[2002];
int n,pairs;
//对结点进行初始化 
void makeset(int t)
{
 bug[t].pre=-1;
 bug[t].rank=0;
}
//递归寻找根节点，同时在回溯过程中进行路径压缩 
int find(int i)
{
 int t=bug[i].pre;
 if(t<0)
  return i;
 bug[i].pre=find(t);
 //路径压缩，修改rank[]的值，两重传递关系
 //该节点与父节点、父节点与根节点 
 bug[i].rank=(bug[i].rank+bug[t].rank)%2;
 
 return bug[i].pre;
 
}
int main()
{
 int time,tt;
 scanf("%d",&time);
 for(tt=1;tt<=time;tt++)
 {
  int n,pair,a,b,x,y,i;
  
  memset(bug,0,sizeof(bug));
  scanf("%d%d",&n,&pair);
  for(i=1;i<=n;i++)
   makeset(i);

  int flag=0;
  for(i=0;i<pair;i++)
  {
   scanf("%d%d",&x,&y);
   if(flag)
    continue;
   a=find(x);
   b=find(y);
   if(a==b)
   {
    if(bug[x].rank==bug[y].rank)//如果x，y已经在一个集合，且他们与根节点的关系相同
      flag=1;
     
    
   }
   else//不在一个集合
   {
		//合并两个等价类 
    bug[a].pre=b;
    //三重传递关系
	//两个节点之间、x与根节点、y与根节点 
    bug[a].rank=(bug[x].rank+bug[y].rank+1)%2;  
   }
  }

 printf("Scenario #%d:\n",tt);
 if(flag)

  printf("Suspicious bugs found!\n\n");
  else
    printf("No suspicious bugs found!\n\n");
 }
 //system("pause");
return 0;
}


