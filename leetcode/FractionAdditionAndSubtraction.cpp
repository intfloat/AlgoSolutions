#include <bits/stdc++.h>
using namespace std;
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
typedef long long ll;
typedef pair<int, int> pii;

struct Fraction {
    int num;
    int den;
    bool positive;
    Fraction(int _num, int _den, bool _positive): num(_num), den(_den), positive(_positive) {}
};

Fraction add(Fraction f1, Fraction f2) {
    int lcm = f1.den * f2.den / __gcd(f1.den, f2.den);
    int n1 = f1.num * (f1.positive ? 1 : -1) * (lcm / f1.den);
    int n2 = f2.num * (f2.positive ? 1 : -1) * (lcm / f2.den);
    int num = n1 + n2;
    bool positive = num >= 0;
    int den = lcm;
    num = max(num, -num);
    int gcd = __gcd(num, den);
    return Fraction(num / gcd, den / gcd, positive);
}

class Solution {
public:
    string fractionAddition(string expression) {
        int ptr = 0;
        Fraction f(0, 1, true);
        while (ptr < expression.size()) {
            int num = 0, den = 0, i = ptr;
            bool positive = true, is_num = true;
            for (; i < expression.size(); ++i) {
                if (expression[i] == '+' || expression[i] == '-') {
                    if (i == ptr) {
                        positive = expression[i] == '+';
                    } else {
                        break;
                    }
                } else if (expression[i] == '/') {
                    is_num = false;
                } else if (is_num) {
                    num = num * 10 + (expression[i] - '0');
                } else {
                    den = den * 10 + (expression[i] - '0');
                }
            }
            ptr = i;
            f = add(f, Fraction(num, den, positive));
        }
        string res;
        if (!f.positive) {
            res.push_back('-');
        }
        res += to_string(f.num);
        res.push_back('/');
        res += to_string(f.den);
        return res;
    }
};


int main() {
    Solution solution;
    cout << solution.fractionAddition("-1/2+1/2") << endl;
    cout << solution.fractionAddition("-1/2+1/2+1/3") << endl;
    cout << solution.fractionAddition("1/3-1/2") << endl;
    cout << solution.fractionAddition("5/3+1/3") << endl;
    return 0;
}
