class Solution {
public:
    string addBinary(string a, string b) {
        int ptr1 = a.size() - 1, ptr2 = b.size() - 1;
        string res;
        int carry = 0;

        while (ptr1 >= 0 || ptr2 >= 0 || carry > 0) {
            int num1 = ptr1 >= 0 ? a[ptr1] - '0' : 0;
            int num2 = ptr2 >= 0 ? b[ptr2] - '0' : 0;
            int sum = num1 + num2 + carry;
            res.push_back((sum % 2 + '0'));
            carry = sum / 2;

            --ptr1;
            --ptr2;
        }

        reverse(res.begin(), res.end());
        return res;
    }
};
