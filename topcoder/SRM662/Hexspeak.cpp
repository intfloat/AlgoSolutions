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

class Hexspeak {
public:
    string decode(long long);
};

string Hexspeak::decode(long long ciphertext) {
    string res;
    while (ciphertext != 0) {
        int rem = ciphertext % 16;
        ciphertext /= 16;
        if (rem > 1 && rem < 10) return "Error!";
        if (rem == 0) {
            res.push_back('O');
        }
        else if (rem == 1) {
            res.push_back('I');
        }
        else {
            res.push_back((char)(rem - 10 + 'A'));
        }
    }
    reverse(res.begin(), res.end());
    return res;
}

<%:testing-code%>
//Powered by [KawigiEdit] 2.0!
