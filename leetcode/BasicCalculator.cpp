class Solution {
private:
    int to_int(string& s) {
        int ret = 0;
        bool neg = (s[0] == '-');
        for (int i = neg; i < s.size(); ++i) {
            ret = ret * 10 + (s[i] - '0');
        }
        if (neg) ret = -ret;
        return ret;
    }
    string to_str(int number) {
        string ret = "";
        bool neg = (number < 0);
        int tmp = number;
        number = abs(number);
        while (number != 0) {
            string tt = "";
            tt = (char)('0' + (number % 10)) + tt;
            ret = tt + ret;
            number = number / 10;
        }
        if (neg) ret = "-" + ret;
        if (ret.empty()) ret = "0";
        return ret;
    }
    string work(string& n1, string& n2, string& op) {
        int x1 = to_int(n1), x2 = to_int(n2);
        if (op == "+") return to_str(x1 + x2);
        if (op == "-") return to_str(x1 - x2);
        return "";
    }
public:
    int calculate(string s) {
        vector<string> arr;
        string cur, tp, op, rr, num;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == ' ') continue;
            if (s[i] == '+' || s[i] == '-' || s[i] == '(' || s[i] == ')') {
                if (!cur.empty()) {
                    arr.push_back(cur);
                    cur = "";
                }
                string tt = "";
                tt += s[i];
                arr.push_back(tt);
            }
            else {
                cur += s[i];
            }
        }
        if (!cur.empty()) {
            arr.push_back(cur);
        }
        stack<string> st;
        for (int i = 0; i < arr.size(); ++i) {
            if (arr[i] == "+" || arr[i] == "-" || arr[i] == "(") {
                st.push(arr[i]);
            }
            else if (arr[i] == ")") {
                rr = st.top(); st.pop(); st.pop();
                if (!st.empty() && (st.top() == "+" || st.top() == "-")) {
                    op = st.top(); st.pop(); num = st.top(); st.pop();
                    rr = work(num, rr, op);
                }
                st.push(rr);
            }
            else {
                rr = arr[i];
                if (!st.empty() && (st.top() == "+" || st.top() == "-")) {
                    op = st.top(); st.pop(); num = st.top(); st.pop();
                    rr = work(num, rr, op);
                }
                st.push(rr);
            }
        }
        int res = to_int(st.top());
        return res;
    }
};
