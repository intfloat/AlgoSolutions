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

class EllysReversals {
public:
    int getMin(vector <string>);
};

//adjacent letters will keep adjacent forever 
//except last one in odd length case
int EllysReversals::getMin(vector <string> words) {
    int len = words.size();
    for(int i=0; i<len; i++){
        vector<string> v;
        int t = words[i].size()/2;
        for(int j=0; j<t; j++){
            string str = words[i].substr(j*2, 2);
            if(str[0] > str[1]){
                char tmp = str[0];
                str[0] = str[1];
                str[1] = tmp;
            }
            v.push_back(str);       
        }
        sort(v.begin(), v.end());
        for(int j=0; j<v.size(); j++){
            words[i][j*2] = v[j][0];
            words[i][j*2+1] = v[j][1];
        }
    }
    sort(words.begin(), words.end());
    int res = 0;
    for(int i=1; i<len; i++){
        if(words[i] == words[i-1]){
            res += 2;
            i++;
        }
    }
    res = len-res;
    return res;
}

<%:testing-code%>
//Powered by [KawigiEdit] 2.0! 
