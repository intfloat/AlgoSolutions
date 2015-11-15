class Solution {
private:
    bool check(int mid, vector<int>& citations) {
        int sz = citations.size();
        return (mid == 0 || citations[sz - mid] >= mid);
    }
public:
    int hIndex(vector<int>& citations) {
        int l = 0, r = citations.size();
        while (l + 1 < r) {
            int mid = (l + r) / 2;
            if (check(mid, citations)) l = mid;
            else r = mid - 1;
        }
        if (check(r, citations)) return r;
        else return l;
    }
};
