class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        if (z > x + y) {
            return false;
        }
        if (z == 0) {
            return true;
        }
        if (x == 0 || y == 0) {
            return x == z || y == z;
        }
        int g = __gcd(x, y);
        return !(z % g);
    }
};
