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

class ABBA {
public:
    string canObtain(string, string);
};

string ABBA::canObtain(string initial, string target) {
    while (target.size() > initial.size()) {
        if (target.back() == 'B') {
            target = target.substr(0, target.size() - 1);
            reverse(target.begin(), target.end());
        }
        else {
            target = target.substr(0, target.size() - 1);
        }
    }
    if (initial == target) {
        return "Possible";
    }
    else {
        return "Impossible";
    }
}

<%:testing-code%>
//Powered by [KawigiEdit] 2.0!
