class Solution {
public:
    string predictPartyVictory(string senate) {
        vector<bool> valid(senate.size(), true);
        int r = 0, d = 0;
        for (int i = 0; i < senate.size(); ++i) {
            if (senate[i] == 'R') ++r;
            else ++d;
        }
        int left = 0, right = 0;
        while (r > 0 && d > 0) {
            if (valid[left]) {
                while (!(valid[right] && senate[right] != senate[left])) {
                    right = (right + 1) % senate.size();
                }
                valid[right] = false;
                if (senate[right] == 'R') --r;
                else --d;
            }
            left = (left + 1) % senate.size();
        }
        return (r > 0) ? "Radiant" : "Dire";
    }
};
