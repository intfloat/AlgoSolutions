//²Á£¬²»¶Ô°¡¡£¡£¡£ 

#include <cstdio>
#include <algorithm>
#include <cmath>
#define NN 10024
#define INF 1E10
#define EPS 1E-10

using namespace std;

struct point { double x, y; };
point p[NN];

double distsqr(point a, point b) {
    return (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y);
}

int n; 
bool xcmp(point a, point b) { return a.x < b.x; }
bool ycmp(int a, int b) { return p[a].y < p[b].y; }

double cpsolve(int a[NN], int L, int R) {
    int i, j, k, n = R-L, q = (L+R)>>1;
    int LT;
    double ans = INF;
    
    //boundary conditions
    if(n<=3){
		for(i=L; i<R; i++){
		for(j=i+1; j<R; j++)
			ans = min(ans, distsqr(p[i], p[j]));
		}
		return ans;
	}
    
    int b[NN];
    for(i = k = 0, j = q - L; k < n; k++)
        if(a[k] <= q && i < (q-L)) b[i++] = a[k];
        else b[j++] = a[k];
    
    ans = min(cpsolve(b, L, q),cpsolve(b+q-L, q+1, R));
    
    int f[NN], t = 0;
    for(k = 0; k < n; k++)
        if(fabs(p[a[k]].x - p[q].x) < ans+EPS)
            f[t++] = a[k];
    for(i = 0; i < t-1; i++) {
        for(j = min(i+7, t-1); j > i; j--) {
            double d = distsqr(p[f[i]], p[f[j]]);
            if(d < ans) ans = d;
        }
    } 
    return ans;
}
double closestpair() {
    int i, a[NN];
    for(i = 0; i < n; i++) a[i] = i;
    sort(p, p+n, xcmp);
    sort(a, a+n, ycmp);
    return cpsolve(a, 0, n);
}

int main(void) {
    int i;
    while(scanf("%d", &n) && n) {
        double ans = INF;
        for(i = 0; i < n; i++) scanf("%lf %lf", &p[i].x, &p[i].y);
        ans = sqrt(closestpair());
        if(ans - 10000.0 > EPS) printf("INFINITY\n");
        else printf("%.4lf\n", ans);
    }
    return 0;
}
