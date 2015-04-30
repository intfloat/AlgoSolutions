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

class IncrementAndDoubling {
public:
    int getMin(vector <int>);
};

int IncrementAndDoubling::getMin(vector <int> desiredArray) {
    int res = 0;    
    vector<int> arr = desiredArray;
    int len = arr.size();
    sort(arr.begin(), arr.end());
    while(arr[len-1] != 0){
        int ones = 0;
        for(int i=0; i<len; i++){
            if(arr[i]%2 == 1) ones++;
        }
        if(ones == 0){
            res++;
        }
        else{
            res += ones;
            res++;
        }
        for(int i=0; i<len; i++)
            arr[i] = arr[i]>>1;
        if(arr[len-1]==0) res--;
    }
    return res;
}

//<%:testing-code%>
//Powered by [KawigiEdit] 2.0!

