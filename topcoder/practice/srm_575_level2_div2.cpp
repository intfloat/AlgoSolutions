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
#define John 0
#define Brus 1

using namespace std;

class TheNumberGameDivTwo {
public:
    string find(int);
};

string TheNumberGameDivTwo::find(int n) {
    int res[1005];
    res[1] = Brus;
    for(int i=2; i<=n; i++){
        res[i] = Brus;
        for(int j=2; j*j<=i; j++){
            if(i%j == 0){
                if(res[i-j]==Brus){
                    res[i] = John;
                    break;
                }
                if(res[i-i/j]==Brus){
                    res[i] = John;
                    break;
                }
            }
        }// end inner for loop
    }
    if(res[n]==John)
        return "John";
    else
        return "Brus";
}

<%:testing-code%>
//Powered by [KawigiEdit] 2.0!
