//A bug's life���鼯�ĵ���Ӧ�� 
//����ǳ���࣬����ʮ����̣���������� 
#include<stdio.h>
#include<algorithm>
#include<string.h>
struct{
  int pre;
  int rank;
 }bug[2002];
int n,pairs;
//�Խ����г�ʼ�� 
void makeset(int t)
{
 bug[t].pre=-1;
 bug[t].rank=0;
}
//�ݹ�Ѱ�Ҹ��ڵ㣬ͬʱ�ڻ��ݹ����н���·��ѹ�� 
int find(int i)
{
 int t=bug[i].pre;
 if(t<0)
  return i;
 bug[i].pre=find(t);
 //·��ѹ�����޸�rank[]��ֵ�����ش��ݹ�ϵ
 //�ýڵ��븸�ڵ㡢���ڵ�����ڵ� 
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
    if(bug[x].rank==bug[y].rank)//���x��y�Ѿ���һ�����ϣ�����������ڵ�Ĺ�ϵ��ͬ
      flag=1;
     
    
   }
   else//����һ������
   {
		//�ϲ������ȼ��� 
    bug[a].pre=b;
    //���ش��ݹ�ϵ
	//�����ڵ�֮�䡢x����ڵ㡢y����ڵ� 
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


