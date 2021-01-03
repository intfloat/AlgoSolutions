class Solution {
public:
    int flipLights(int n, int m) {
        if (n == 0 || m == 0) {
            return 1;
        }
        n = min(n, 4);
        int total = (1 << n);
        int mask = total - 1;
        vector<bool> visited(total, false);
        visited[mask] = true;

        for (int i = 0; i < m; ++i) {
            vector<bool> n_visited(total, false);
            for (int j = 0; j < total; ++j) {
                if (!visited[j]) {
                    continue;
                }

                // flip all
                n_visited[mask & (~j)] = true;

                // flip odd
                int odd = j ^ 1;
                odd = odd ^ (1 << 2);
                n_visited[odd & mask] = true;

                // flip even
                int even = j ^ (1 << 1);
                even = even ^ (1 << 3);
                n_visited[even & mask] = true;

                // flip 3k + 1
                int kk = j ^ 1;
                kk = kk ^ (1 << 3);
                n_visited[kk & mask] = true;
            }

            visited = n_visited;
        }

        int res = 0;
        for (int i = 0; i < total; ++i) {
            res += visited[i];
        }
        return res;
    }
};
