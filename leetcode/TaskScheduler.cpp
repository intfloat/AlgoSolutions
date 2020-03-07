class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if (n <= 0 || tasks.empty()) {
            return tasks.size();
        }
        vector<int> cnt(26, 0);
        for (int i = 0; i < tasks.size(); ++i) {
            ++cnt[tasks[i] - 'A'];
        }
        int mx_val = *max_element(cnt.begin(), cnt.end());
        int mx_cnt = 0;
        for (int i = 0; i < cnt.size(); ++i) {
            mx_cnt += (cnt[i] == mx_val);
        }
        if (mx_cnt >= n + 1) {
            return tasks.size();
        }
        int interval = (mx_val - 1) * (n + 1) + mx_cnt;
        return max(interval, (int)tasks.size());
    }
};
