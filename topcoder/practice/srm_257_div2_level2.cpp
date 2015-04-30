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

class Haar1D {
public:
    vector <int> transform(vector <int>, int);
};

vector <int> Haar1D::transform(vector <int> data, int L) {
    int len = data.size();
    vector<int> res = data;
    for(int i=0; i<L; i++){
        vector<int> tmp;
        int num = len>>i;
        // former half part
        for(int j=0; j<num/2; j++)
            tmp.push_back(res[j*2]+res[j*2+1]);
        // latter half part
        for(int j=0; j<num/2; j++)
            tmp.push_back(res[j*2]-res[j*2+1]);
        // put data into final vector
        for(int j=0; j<num; j++)
            res[j] = tmp[j];
    }
    return res;
}

<%:testing-code%>
//Powered by [KawigiEdit] 2.0!
