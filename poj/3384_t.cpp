#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <climits>

using namespace std;

const int MAX = 110;
struct point {double x,y;};
struct line{point a,b; double ang;};
point p[MAX],s[MAX];
line ln[MAX],deq[MAX];
const double eps = 1e-6;
bool dy(double x,double y)  {   return x > y + eps;}    // x > y
bool xy(double x,double y)  {   return x < y - eps;}    // x < y
bool dyd(double x,double y) {   return x > y - eps;}    // x >= y
bool xyd(double x,double y) {   return x < y + eps;}    // x <= y
bool dd(double x,double y)  {   return fabs( x - y ) < eps;}  // x == y
double disp2p(point a,point b) //  a b 两点之间的距离
{
    return sqrt( ( a.x - b.x ) * ( a.x - b.x ) + ( a.y - b.y ) * ( a.y - b.y ) );
}
double crossProduct(point a,point b,point c)//向量 ac 在 ab 的方向
{
    return (c.x - a.x)*(b.y - a.y) - (b.x - a.x)*(c.y - a.y);
}
bool parallel(line u,line v)
{
    return dd( (u.a.x - u.b.x)*(v.a.y - v.b.y) - (v.a.x - v.b.x)*(u.a.y - u.b.y) , 0.0 );
}
point l2l_inst_p(line l1,line l2)
{
    point ans = l1.a;
    double t = ((l1.a.x - l2.a.x)*(l2.a.y - l2.b.y) - (l1.a.y - l2.a.y)*(l2.a.x - l2.b.x))/
               ((l1.a.x - l1.b.x)*(l2.a.y - l2.b.y) - (l1.a.y - l1.b.y)*(l2.a.x - l2.b.x));
    ans.x += (l1.b.x - l1.a.x)*t;
    ans.y += (l1.b.y - l1.a.y)*t;
    return ans;
}

bool equal_ang(line a,line b)   // 第一次unique的比较函数
{
    return dd(a.ang,b.ang);
}
bool cmphp(line a,line b)   // 排序的比较函数
{
    if( dd(a.ang,b.ang) ) return xy(crossProduct(b.a,b.b,a.a),0.0);
    return xy(a.ang,b.ang);
}
bool equal_p(point a,point b)//第二次unique的比较函数
{
    return dd(a.x,b.x) && dd(a.y,b.y);
}
void makeline_hp(double x1,double y1,double x2,double y2,line &l)
{
    l.a.x = x1; l.a.y = y1; l.b.x = x2; l.b.y = y2;
    l.ang = atan2(y2 - y1,x2 - x1);
}
void makeline_hp(point a,point b,line &l) // 线段(向量ab)左侧侧区域有效
{
    l.a = a; l.b = b;
    l.ang = atan2(b.y - a.y,b.x - a.x); // 如果是右侧区域，改成a.y - b.y,a.x - b.x
}
void inst_hp_nlogn(line *ln,int n,point *s,int &len)
{
    len = 0;
    sort(ln,ln+n,cmphp);
    n = unique(ln,ln+n,equal_ang) - ln;
    int bot = 0,top = 1;
    deq[0] = ln[0]; deq[1] = ln[1];
    for(int i=2; i<n; i++)
    {
        if( parallel(deq[top],deq[top-1]) || parallel(deq[bot],deq[bot+1]) )
            return ;
        while( bot < top && dy(crossProduct(ln[i].a,ln[i].b,
            l2l_inst_p(deq[top],deq[top-1])),0.0) )
            top--;
        while( bot < top && dy(crossProduct(ln[i].a,ln[i].b,
            l2l_inst_p(deq[bot],deq[bot+1])),0.0) )
            bot++;
        deq[++top] = ln[i];
    }
    while( bot < top && dy(crossProduct(deq[bot].a,deq[bot].b,
        l2l_inst_p(deq[top],deq[top-1])),0.0) ) top--;
    while( bot < top && dy(crossProduct(deq[top].a,deq[top].b,
        l2l_inst_p(deq[bot],deq[bot+1])),0.0) ) bot++;
    if( top <= bot + 1 ) return ;

    for(int i=bot; i<top; i++)
        s[len++] = l2l_inst_p(deq[i],deq[i+1]);
    if( bot < top + 1 ) s[len++] = l2l_inst_p(deq[bot],deq[top]);
    len = unique(s,s+len,equal_p) - s;
}
void changepoint(point a,point b,point &c,point &d,double h)
{
    double len = disp2p(a,b);
    double dx = h / len * ( a.y - b.y );
    double dy = h / len * (-a.x + b.x );
    c.x = a.x + dx; c.y = a.y + dy;
    d.x = b.x + dx; d.y = b.y + dy;
}
void dis_max(point *p,int len,point &c1,point &c2)
{
    double d = -1e20;
    if( len == 1 )
    {
        c1 = c2 = p[0];
        return ;
    }
    for(int i=0; i<len; i++)
        for(int k=i+1; k<len; k++)
        {
            double l = disp2p(p[i],p[k]);
            if( dy(l,d) )
            {
                d = l;
                c1 = p[i]; c2 = p[k];
            }
        }
}
int main()
{
    int n,len;
    double r;
    point c,d;
    while( ~scanf("%d%lf",&n,&r) )
    {
        for(int i=n-1; i>=0; i--)
            scanf("%lf%lf",&p[i].x,&p[i].y);
        p[n] = p[0];
        for(int i=0; i<n; i++)
        {
            changepoint(p[i],p[i+1],c,d,r);
            makeline_hp(c,d,ln[i]);
        }
        inst_hp_nlogn(ln,n,s,len);
        point c1,c2;
        dis_max(s,len,c1,c2);
        printf("%.4lf %.4lf %.4lf %.4lf\n",c1.x,c1.y,c2.x,c2.y);
    }
return 0;
}
