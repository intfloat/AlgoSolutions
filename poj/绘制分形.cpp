/*
����Ϊn�ĺ��η���,���С��3^(n-1)*3^(n-1).�������ַ��������洢���η����и����ַ�,��Ϊn<=7,��3^6=729,��˿��Զ���һ��СΪ731*731���ַ��������洢����������7�ĺ��η���.
����Ϊn�ĺ��η��ο��������µ���ʽ�ӱ�ʾ:
                        B(n - 1)        B(n - 1)
                                B(n - 1)
                        B(n - 1)        B(n - 1)
��˿�����һ���ݹ麯�������ö���Ϊn�ĺ��η���,������Ҫ��(x,y)λ�ÿ�ʼ���ö���Ϊn�ĺ��η���,����5������Ϊ(n-1)�ĺ��η������,����ʼλ�÷ֱ�Ϊ:(x,y),(x+2*l,y),(x+l,y+l),(x,y+2*l),(x+2*l,y+2*l),����l=3^(n-2).�õݹ麯���Ľ���������:��n=1ʱ(������Ϊ1�ĺ��η���),ֻ����(x,y)λ������һ���ַ�'X'�ַ�.
����,��Ŀ���ᵽ"��ÿ�е�ĩβ��Ҫ����κζ���Ŀո�",������ַ�������ÿ�����һ��'X'�ַ�֮��,Ӧ�������ַ���������־'\0'.
*/
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

char map[731][731];

void dfs(int n,int x,int y)
{
	int size;
	if(n==1)
	{
		map[x][y]='X';
		return ;
	}
	size=(int)pow(3.0,n-2);
	dfs(n-1,x,y);       //���Ͻ�
	dfs(n-1,x,y+2*size);       //���Ͻ�
	dfs(n-1,x+size,y+size);    //�м�
	dfs(n-1,x+2*size,y);       //���½�
	dfs(n-1,x+2*size,y+2*size);   //���½�
}
int main(void)
{
	int i,j,n,size;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==-1)
			break;
		size=(int)pow(3.0,n-1);
		for(i=1;i<=size;i++)
		{
			for(j=1;j<=size;j++)
				map[i][j]=' ';
		}
		dfs(n,1,1);

		for(i=1;i<=size;i++)
		{
			for(j=1;j<=size;j++)
				printf("%c",map[i][j]);
			printf("\n");
		}
		printf("-\n");
	}
	return 0;
}
