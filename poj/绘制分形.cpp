/*
度数为n的盒形分形,其大小是3^(n-1)*3^(n-1).可以用字符数组来存储盒形分形中各个字符,因为n<=7,而3^6=729,因此可以定义一大小为731*731的字符数组来存储度数不超过7的盒形分形.
度数为n的盒形分形可以有以下递推式子表示:
                        B(n - 1)        B(n - 1)
                                B(n - 1)
                        B(n - 1)        B(n - 1)
因此可以用一个递归函数来设置度数为n的盒形分形,假设需要在(x,y)位置开始设置度数为n的盒形分形,它有5个度数为(n-1)的盒形分形组成,其起始位置分别为:(x,y),(x+2*l,y),(x+l,y+l),(x,y+2*l),(x+2*l,y+2*l),其中l=3^(n-2).该递归函数的结束条件是:当n=1时(即度数为1的盒形分形),只需在(x,y)位置设置一个字符'X'字符.
另外,题目中提到"在每行的末尾不要输出任何多余的空格",因此在字符数组中每行最后一个'X'字符之后,应该设置字符串结束标志'\0'.
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
	dfs(n-1,x,y);       //左上角
	dfs(n-1,x,y+2*size);       //右上角
	dfs(n-1,x+size,y+size);    //中间
	dfs(n-1,x+2*size,y);       //左下角
	dfs(n-1,x+2*size,y+2*size);   //右下角
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
