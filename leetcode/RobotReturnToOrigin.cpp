class Solution {
public:
    bool judgeCircle(string moves) {
        int u = 0, d = 0, l = 0, r = 0;
        for (int i = 0; i < moves.size(); ++i) {
            u += (moves[i] == 'U');
            d += (moves[i] == 'D');
            l += (moves[i] == 'L');
            r += (moves[i] == 'R');
        }
        return (u == d) && (l == r);
    }
};
