#include<iostream>
using namespace std;
#define MAX 700
struct POINT
{
	int x, y;
}point[MAX];
int main()
{
//freopen("in.txt", "r", stdin);
//¸¡µãÔËËãÌ«Âı
	int i, j, k;
	int n, max, tmp, a, b;
	while(scanf("%d", &n), n)
	{
		max = 0;
		for(i=0; i<n; i++)
			scanf("%d %d", &point[i].x, &point[i].y);
		for(i=0; i<n; i++)
		{
			for(j=i+1; j<n; j++)
			{
				tmp = 0;
				a = point[j].y - point[i].y;
				b = point[j].x - point[i].x;
				for(k=j+1; k<n; k++)
					if(a * (point[k].x - point[i].x) == (point[k].y - point[i].y) * b)
						tmp++;
				if(max < tmp)
					max = tmp;
			}
		}
		printf("%d\n", max+2);
	}
	system("pause");
	return 0;
}
