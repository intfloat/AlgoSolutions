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

class KnightCircuit2 {
public:
    int maxSize(int, int);
};

int KnightCircuit2::maxSize(int w, int h) {
    if(w==1 || h==1)
        return 1;
    else if(w==2)
        return (h+1)/2;
    else if(h==2)
        return (w+1)/2;
    else if(h==3 && w==3)
        return 8;
    else return w*h;
}

<%:testing-code%>
//Powered by [KawigiEdit] 2.0!
