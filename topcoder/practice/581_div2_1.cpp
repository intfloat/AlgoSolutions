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

class BlackAndWhiteSolitaire {
public:
    int minimumTurns(string);
};

int BlackAndWhiteSolitaire::minimumTurns(string cardFront) {
    int len = cardFront.size();
    int res = 0;
    for(int i=0; i<len; i++){
        if(i%2==0 && cardFront[i]!='B')
            res++;
        if(i%2==1 && cardFront[i]!='W')
            res++;
    }
    int tmp = res;
    res = 0;
    for(int i=0; i<len; i++){
        if(i%2==1 && cardFront[i]!='B')
            res++;
        if(i%2==0 && cardFront[i]!='W')
            res++;
    }
    return min(res, tmp);
}

<%:testing-code%>
//Powered by [KawigiEdit] 2.0!
