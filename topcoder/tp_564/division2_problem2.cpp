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

class AlternateColors {
public:
    string getColor(long long, long long, long long, long long);
};

string AlternateColors::getColor(long long r, long long g, long long b, long long k) {
    string colors[3]={"RED","GREEN","BLUE"};
    long long array[3]={r,g,b};
    long long minimum=min(r,min(g,b));
    
    if(k <= minimum*3){
        k=(k-1)%3;
        return colors[k];
    }
    k-=minimum*3;
    r-=minimum; g-=minimum; b-=minimum; 
    for(int i=0;i<3;i++)
        array[i]-=minimum;
    sort(array,array+3);
    minimum=array[1];
    if(k <= minimum*2){
        k=(k-1)%2;
        if(k==0){
            if(r !=0)
                return "RED";
            if(g !=0)
                return "GREEN";
        }
        else if(k==1){
            if(b !=0)
                return "BLUE";
            if(g !=0)
                return "GREEN";
        }
    }
    r-=minimum; g-=minimum; b-=minimum;
    if(r >0)
        return "RED";
    else if(g >0)
        return "GREEN";
    return "BLUE";
}

//<%:testing-code%>
//Powered by [KawigiEdit] 2.0!
