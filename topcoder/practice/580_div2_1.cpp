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

class ShoutterDiv2 {
public:
    int count(vector <int>, vector <int>);
};

int ShoutterDiv2::count(vector <int> s, vector <int> t) {
    int len = s.size();
    int res = 0;
    for(int i=0; i<len; i++)
    for(int j=i+1; j<len; j++){
        if(s[i]<=s[j] && t[i]>=s[j])
            res++;
        else if(s[i]<=t[j] && t[i]>=t[j])
            res++;
        else if(s[i]>=s[j] && t[i]<=t[j])
            res++;
    }
    return res;
}

<%:testing-code%>
//Powered by [KawigiEdit] 2.0!
