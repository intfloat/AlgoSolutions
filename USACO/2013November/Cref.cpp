#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

int DP[1010][1010];

int main() {
  freopen("pogocow.in", "r", stdin);
  freopen("pogocow.out", "w", stdout);

  int N; cin >> N;

  vector<pair<int, int> > A(N);
  for(int i = 0; i < N; i++) 
    cin >> A[i].first >> A[i].second;
  sort(A.begin(), A.end());

  int result = 0;
  for(int ii = 0; ii < 2; ii++) {
    for(int i = N - 1; i >= 0; i--) {
      int k = N;
      int val = 0;
      for(int j = 0; j <= i; j++) {
        while(k - 1 > i &&
              A[k - 1].first - A[i].first >= A[i].first - A[j].first) {
          --k;
          val = max(val, A[k].second + DP[k][i]);
        }
        DP[i][j] = val;
      }
      result = max(result, A[i].second + val);
    }
    for(int i = 0; i < N; i++) {
      A[i].first = -A[i].first;
    }
    reverse(A.begin(), A.end());
  }

  cout << result << endl;
  return 0;
}

