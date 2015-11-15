class Solution {
public:
    int computeSum(int number) {
        int res = 0;
        while (number != 0) {
            res += (number % 10) * (number % 10);
            number /= 10;
        }
        return res;
    }
    
    bool isHappy(int n) {
        set<int> visited;
        while (true) {
            if (n == 1) return true;
            n = computeSum(n);
            if (visited.find(n) != visited.end()) return false;
            else visited.insert(n);
        }
    }
};
