#include <stdio.h>
#include <vector>
#include <cmath>
#include <string.h>
#include <algorithm>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;

const int MAX_N = 500005;
bool prime[500005];

void compute_prime() {
    memset(prime, true, sizeof prime);
    int bound = sqrt(MAX_N) + 1;
    prime[0] = prime[1] = false;
    for (int i = 2; i <= bound; ++i) {
        if (!prime[i]) continue;
        for (int j = i * i; j < MAX_N; j += i) prime[j] = false;
    }
    return;
}

int N;
vector<int> numbers;
vector<vector<int> > g;
vector<int> pre;
vector<bool> visited;
bool dfs(int i) {
    visited[i] = true;
    FOR(j, g[i].size()) {
        int to = g[i][j];
        if (visited[N + to]) continue;
        visited[N + to] = true;
        if (pre[to] == -1 || dfs(pre[to])) {        
            pre[to] = i;
            return true;
        }
    }
    return false;
}

int match() {
    pre.resize(N); visited.resize(N * 2);
    int res = 0;
    fill(pre.begin(), pre.end(), -1);    
    FOR(i, N) {
        fill(visited.begin(), visited.end(), false);        
        res += dfs(i);
    }
    return res;
}

void solve() {    
    scanf("%d", &N);
    numbers.resize(N); g.resize(N);
    FOR(i, N) g[i].clear();
    FOR(i, N) scanf("%d", &numbers[i]);
    sort(numbers.begin(), numbers.end());
    FOR(i, N) for (int j = i + 1; j < N; ++j) {
        if (numbers[j] % numbers[i] == 0 && prime[numbers[j] / numbers[i]]) {            
            g[i].push_back(j); g[j].push_back(i);            
        }
    }
    printf("%d\n", N - match() / 2);
    return;
}

int main() {
    int T;
    scanf("%d", &T);
    compute_prime();
    FOR(tt, T) {
        printf("Case #%d: ", tt + 1);
        solve();
    }
    return 0;
}
