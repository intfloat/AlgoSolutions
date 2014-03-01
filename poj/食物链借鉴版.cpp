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
        //��һ�ִ������� 
        if(x>n||y>n) wrong++;
        //�ڶ��ִ������� 
        else if(x==y&&d==2) wrong++;
        else 
        {
			//Ѱ�Ҹ��ڵ� 
            int xx=findPa(x);
            int yy=findPa(y);
            //λ��һ���ȼ����еĴ������� 
            if(xx==yy)
            {
                if(d==1&&(a[x].ki!=a[y].ki)) wrong++;
                if(d==2&&(a[y].ki-a[x].ki+3)%3!=1) wrong++;
            }
            //λ�ڲ�ͬ�ȼ���Ĵ������� 
            else
            {
				a[xx].pa=yy;
				//�ϲ������ȼ���֮��ı�ڵ���ϵ 
				a[xx].ki=(a[y].ki-(a[x].ki+d-1)+3)%3;                
            } 
        }
    }
    printf("%d\n",wrong);
    //system("pause");
    return 0;
}
