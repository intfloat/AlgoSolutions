class Solution {
public:
    int calculate(string s) {
        int sz = s.size();
        int number = 0;
        stack<char> op;
        stack<int> ns;
        for (int i = 0; i < sz; ++i) {
            if (s[i] == ' ') {
                continue;
            }
            else if (s[i] >= '0' && s[i] <= '9') {
                number = number * 10 + (s[i] - '0');
            }
            else {
                ns.push(number);
                while (!op.empty() && (op.top() == '*' || op.top() == '/')) {
                    char tp = op.top();
                    op.pop();
                    int t2 = ns.top(); ns.pop();
                    int t1 = ns.top(); ns.pop();
                    if (tp == '*') {
                        ns.push(t1 * t2);
                    }
                    else {
                        ns.push(t1 / t2);
                    }
                }
                op.push(s[i]);
                number = 0;
            }
        }
        ns.push(number);
        // need to check last operator
        while (!op.empty() && (op.top() == '*' || op.top() == '/')) {
            char tp = op.top();
            op.pop();
            int t2 = ns.top(); ns.pop();
            int t1 = ns.top(); ns.pop();
            if (tp == '*') {
                ns.push(t1 * t2);
            }
            else {
                ns.push(t1 / t2);
            }
        }
        vector<char> ap;
        stack<int> an;
        while (!op.empty()) {
            ap.push_back(op.top());
            op.pop();
        }
        reverse(ap.begin(), ap.end());
        while (!ns.empty()) {
            an.push(ns.top());
            ns.pop();
        }
        for (int i = 0; i < ap.size(); ++i) {
            char tp = ap[i];
            int t1 = an.top(); an.pop();
            int t2 = an.top(); an.pop();
            if (tp == '+') an.push(t1 + t2);
            else an.push(t1 - t2);
        }
        return an.top();
    }
};
