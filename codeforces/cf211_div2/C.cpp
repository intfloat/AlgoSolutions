#include <vector>
#include <list>
#include <limits.h>
#include <map>
#include <set>
#include <deque>
#include <queue>
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
#include <string.h>
#include <stdlib.h>
using namespace std;

int main(){
    string str;
    cin>>str;
    int len = str.size();
    string s1 = str.substr(0, 2);
    for (int i = 2; i < len; ++i) {
        if (str[i] == str[i - 1] && str[i] == str[i -2]) continue;
        s1 += str[i];
    }
    // cout << "s1: " << s1 << endl;
    len = s1.size();
    string res = s1.substr(0, 3);
    for (int i = 3; i < len; ++i) {
        if (s1[i] == s1[i -1] && s1[i -2] == s1[i - 3]) {
            res += s1.substr(i + 1, 3);
            i += 3;
        }
        else res += s1[i];
    }
    cout<<res<<endl;
	return 0;
}
