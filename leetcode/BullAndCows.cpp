class Solution {
public:
    string getHint(string secret, string guess) {
        int bull = 0, cow = 0;
        vector<int> s(10, 0), g(10, 0);
        for (int i = 0; i < (int)secret.size(); ++i) {
            if (secret[i] == guess[i]) {
                ++bull;
            }
            else {
                ++s[secret[i] - '0'];
                ++g[guess[i] - '0'];
            }
        }
        for (int i = 0; i < 10; ++i) {
            cow += min(s[i], g[i]);
        }
        stringstream ss;
        ss << bull << "A" << cow << "B";
        string res;
        ss >> res;
        return res;
    }
};
