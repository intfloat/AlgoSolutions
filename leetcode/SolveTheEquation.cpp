#include <bits/stdc++.h>
using namespace std;
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
typedef long long ll;
typedef pair<int, int> pii;

struct Term {
    bool positive;
    int coef;
    bool has_x;
    bool left;
    bool has_digit;
    Term(bool _left): positive(true), left(_left), has_x(false), coef(0), has_digit(false) {}
};

class Solution {
public:
    string solveEquation(string equation) {
        bool left = true;
        vector<Term> terms;
        Term term(left);
        FOR(i, equation.size()) {
            char c = equation[i];
            if (c == 'x') {
                term.has_x = true;
            } else if (c <= '9' && c >= '0') {
                term.coef = term.coef * 10 + (c - '0');
                term.has_digit = true;
            } else if (c == '+' || c == '-') {
                if (i > 0 && equation[i - 1] != '=') {
                    terms.push_back(term);
                }
                term = Term(left);
                term.positive = (c == '+');
            } else if (c == '=') {
                terms.push_back(term);
                left = false;
                term = Term(left);
            }
        }
        terms.push_back(term);

        int x_coef = 0, num_coef = 0;
        for (auto& t : terms) {
            if (!t.has_digit) {
                t.coef = 1;
            }
            if (!t.positive) {
                t.coef = -t.coef;
                t.positive = true;
            }
            if (t.has_x) {
                x_coef += t.left ? t.coef : -t.coef;
            } else {
                num_coef += t.left ? -t.coef : t.coef;
            }
        }
        if (x_coef == 0 && num_coef == 0) {
            return "Infinite solutions";
        } else if (x_coef == 0 && num_coef != 0) {
            return  "No solution";
        } else {
            return "x=" + to_string(num_coef / x_coef);
        }
    }
};

int main() {
    Solution solution;
    cout << solution.solveEquation("-x=1") << endl;
    cout << solution.solveEquation("-x=-1") << endl;
    cout << solution.solveEquation("x+5-3+x=6+x-2") << endl;
    cout << solution.solveEquation("x=x") << endl;
    cout << solution.solveEquation("2x=x") << endl;
    cout << solution.solveEquation("2x+3x-6x=x+2") << endl;
    cout << solution.solveEquation("x=x+2") << endl;
    return 0;
}
