#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

struct tpoint {
	int x, y;
} p[1100], q[1100];

int n, m, L;
double ans;

void init()
{
	int i;

	cin >> n >> L;
	for (i=0; i<n; i++)
		cin >> p[i].x >> p[i].y;
}

int dbl(tpoint a, tpoint b, tpoint c)
{
	return (b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x);
}

int cmp(const void*p1, const void*p2)
{
	tpoint a(*(tpoint*)p1), b(*(tpoint*)p2);
	if (a.y==b.y)
		return a.x-b.x;
	else
		return a.y-b.y;
}

double dis(tpoint a, tpoint b)
{
	return sqrt((b.x-a.x)*(b.x-a.x)+(b.y-a.y)*(b.y-a.y));
}

double bound(tpoint a, tpoint b, tpoint c)
{
	double da=dis(a, b), db=dis(b, c), dc=dis(a, c);
	double cosangle=(dc*dc-da*da-db*db)/(2*da*db);

	return double(L)*acos(cosangle);
}
void add(tpoint a, int k)
{
	while (m>k && dbl(q[m-2], q[m-1], a)<=0)
		m--;
	q[m++]=a;
}

void work()
{
	int i, m1;

	qsort(p, n, sizeof(tpoint), cmp);
	m=0;
	for (i=0; i<n; i++)
		add(p[i], 1);
	m1=m;
	for (i=n-2; i>=0; i--)
		add(p[i], m1);
	q[m]=q[1];

	ans=0;
	for (i=0; i<m-1; i++)
	{
		ans+=dis(q[i], q[i+1]);
	//	ans+=bound(q[i], q[i+1], q[i+2]);
	}
	ans+=2*3.1415926*L;
	cout.setf(ios::fixed);
	cout << setprecision(0) << ans << endl;
}

int main()
{
	init();
	work();
	system("pause");
	return 0;
}

