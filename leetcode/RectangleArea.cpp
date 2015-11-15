class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        if (A > E) {
            return computeArea(E, F, G, H, A, B, C, D);
        }
        else {
            int s1 = (C - A) * (D - B);
            int s2 = (G - E) * (H - F);
            if (E >= C) return s1 + s2;
            if (E < C && (H <= B || F >= D)) return s1 + s2;
            else {
                return s1 + s2 - (min(D, H) - max(B, F)) * (min(C, G) - E);
            }
        }
    }
};
