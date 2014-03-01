#include <iostream>

using namespace std;

int mark[10001], f[10001], s[101], n, m;
int i, j, q, x, y;

int main()
{
	while (cin >> n, n!=0)
	{
		for (i=1; i<=n; i++)
			cin >> s[i];
		cin >> q;
		memset(mark, 0xFF, sizeof(mark));
		for (i=0; i<=10000; i++)
		{
			for (j=1; j<=n; j++)
				if (i>=s[j])
					mark[f[i-s[j]]]=i;
			f[i]=0;
			while (mark[f[i]]==i) f[i]++;
		}
		for(i=0;i<=12;i++){
			cout<<i<<" goal: "<<f[i]<<endl;
		}
		for (i=1; i<=q; i++)
		{
			x=0;
			cin >> m;
			for (j=1; j<=m; j++)
			{
				cin >> y;
				x=x^f[y];
			}
			if (x==0) cout << "L"; else cout << "W";
		}
		cout << endl;
	}
	return 0;
}
