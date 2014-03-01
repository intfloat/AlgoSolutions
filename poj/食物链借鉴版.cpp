#include<iostream>
#include<stdio.h>
#define SIZE 50010
using namespace std;
int n,k;
int d,x,y;
struct node
{
    int pa;
    int ki;
}a[SIZE];
void Init(int n)
{
    for(int i=1;n-i>=0;i++)
    {
        a[i].pa=i;
        a[i].ki=0;
    }
}
int findPa(int n)
{
    if(a[n].pa!=n)
    {
        int Pa=a[n].pa;
        int Root=findPa(a[n].pa);
        a[n].ki=(a[n].ki+a[Pa].ki+3)%3;
        return a[n].pa=Root;
    }
    else return n;
}
/*void Union(int x,int y,int del)
{
    int xx=findPa(x);
    int yy=findPa(y);
    a[xx].pa=yy;
    a[xx].ki=(a[y].ki-(a[x].ki+del)+3)%3;
}*/
int main()
{
    scanf("%d %d",&n,&k);
    Init(n);
    int wrong=0;
    for(int i=0;k-i>0;i++)
    {
        scanf("%d %d %d",&d,&x,&y);
        //第一种错误情形 
        if(x>n||y>n) wrong++;
        //第二种错误情形 
        else if(x==y&&d==2) wrong++;
        else 
        {
			//寻找父节点 
            int xx=findPa(x);
            int yy=findPa(y);
            //位于一个等价类中的错误情形 
            if(xx==yy)
            {
                if(d==1&&(a[x].ki!=a[y].ki)) wrong++;
                if(d==2&&(a[y].ki-a[x].ki+3)%3!=1) wrong++;
            }
            //位于不同等价类的错误情形 
            else
            {
				a[xx].pa=yy;
				//合并两个等价类之后改变节点间关系 
				a[xx].ki=(a[y].ki-(a[x].ki+d-1)+3)%3;                
            } 
        }
    }
    printf("%d\n",wrong);
    //system("pause");
    return 0;
}
