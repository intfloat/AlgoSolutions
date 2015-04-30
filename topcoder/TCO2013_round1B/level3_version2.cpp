 #include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

// About probability and expected values
// Take advantage of the linearity of expected values
// and divide the original problems
// Transformation of data type is very important in solving this problem
class TheKnights {
public:
    double find(int, int, int);
    double single(int n, int a, int b);
    double inter(int n, int a, int b);
};

// Only can be attacked by one knight
double TheKnights::single(int n, int a, int b) {
    //define directions
    const double dx[] = {a, b, -a, -b, 0, a, b, -a, -b};
    const double dy[] = {b, -a, b, -a, 0, -b, a, -b, a};
    double res = 0;
    double p = 1.0/((double)n*n);
    int i = 9;
    if(a == b)
        i = 5;
    for(int j=0; j<i; j++){
        double minx = max(0.0, dx[j]);
        double maxx = min(n-1+dx[j], (double)n-1);
        double miny = max(0.0, dy[j]);
        double maxy = min(n-1+dy[j], (double)n-1);
        double x = max(0.0, maxx-minx+1);
        double y = max(0.0, maxy-miny+1);
        //cout<<"x: "<<x<<endl;
        //cout<<"y: "<<y<<endl;
        res += (x*y);
    }
//  cout<<"single: "<<res<<endl;
    return res*p;
}

// Can be attacked by two knights
double TheKnights::inter(int n, int a, int b) {
    //define directions
    const double dx[] = {a, b, -a, -b, 0, a, b, -a, -b};
    const double dy[] = {b, -a, b, -a, 0, -b, a, -b, a};
    double res = 0;
    double p = 2.0/(((double)n*n)*(((double)n*n)-1));
    int i = 9;
    if(a == b)
        i = 5;
    for(int j=0; j<i; j++)
    for(int k=(j+1); k<i; k++){
        double minx = max(0.0, max(dx[j], dx[k]));
        double maxx = min((double)n-1, min(n-1+dx[j], n-1+dx[k]));
        double miny = max(0.0, max(dy[j], dy[k]));
        double maxy = min((double)n-1, min(n-1+dy[j], n-1+dy[k]));
        double x = max(0.0, maxx-minx+1);
        double y = max(0.0, maxy-miny+1);
        res += (x*y);
    }
    //cout<<"inter: "<<res<<endl;
    return res*p;
}

double TheKnights::find(int n, int a, int b) {
    return 2*single(n,a,b)-inter(n,a,b);
}

//<%:testing-code%>
//Powered by [KawigiEdit] 2.0!
