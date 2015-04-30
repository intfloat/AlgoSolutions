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

class ValueHistogram {
public:
    vector <string> build(vector <int>);
};

vector <string> ValueHistogram::build(vector <int> values) {
    int len = values.size();
    int count[11], max_number=0;
    memset(count, 0, sizeof(count));
    
    //count values
    for(int i=0; i<len; i++){
        count[values[i]]++;
        max_number = max(max_number, count[values[i]]);
    }
    
    //initial the vector
    vector<string> res(max_number + 1);
    for(int i=0; i<=max_number; i++){
        string str = "..........";
        res[i] = str;
    }
    //change the vector contents to get the results
    for(int i=0; i<10; i++){
        for(int j=0; j<count[i]; j++){
            res[max_number-j][i] = 'X';
        }
    }
    return res;
}

//<%:testing-code%>
//Powered by [KawigiEdit] 2.0!

