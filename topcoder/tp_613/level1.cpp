// level1.cpp
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

class TaroFriends {
public:
    int getNumber(vector <int>, int);
};

// failed system test...
int TaroFriends::getNumber(vector <int> coordinates, int X) {
    int len = coordinates.size();
    sort(coordinates.begin(), coordinates.end());
    long long mx = coordinates[len-1];
    for(int i=0; i<len; i++){
        if((mx - coordinates[i]) > X){
            coordinates[i] += 2*X;
            mx = max(mx, (long long)coordinates[i]);
        }
        else{
            break;
        }
    }
    sort(coordinates.begin(), coordinates.end());
    int res = coordinates[len-1]-coordinates[0];
    return res;
}

<%:testing-code%>
//Powered by [KawigiEdit] 2.0!