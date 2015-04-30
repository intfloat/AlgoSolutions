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

class TheArray {
public:
    int find(int, int, int, int);
};

int TheArray::find(int n, int d, int first, int last) {
    int res = max(last, first);
    d = max(d, -d);
    for(int i=1; i<n-1; i++){
        int num1 = first+i*d;
        int num2 = last+(n-1-i)*d;
        res = max(res, min(num1, num2));
    }
    return res;
}

int main(){
    TheArray array;
    int n = 3;
    int d = 1;
    int first = 12;
    int last = 13;
    cout<<array.find(n, d, first, last)<<endl;
    system("pause");
}

//<%:testing-code%>
//Powered by [KawigiEdit] 2.0!
