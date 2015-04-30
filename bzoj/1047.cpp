#include <iostream>
#include <deque>
#include <stdio.h>
#include <limits.h>
#include <algorithm>
#include <cassert>

using namespace std;

const int MAX_N = 1005;
int arr[MAX_N][MAX_N];

int main() {
    int a, b, n;
    scanf("%d%d%d", &a, &b, &n);
    for (int i = 0; i < a; ++i)
    for (int j = 0; j < b; ++j)
        scanf("%d", arr[i] + j);
    // cout << "here" << endl;
    pair<int, int> res[MAX_N][MAX_N];
    deque<pair<int, int> > minq, maxq;

    // first iteration
    // pretty similar to the problem of SlidingWindow
    for (int i = 0; i < a; ++i) {
        // cout << "tag 3: " << i << endl;
        while(!minq.empty()) minq.pop_front();
        while(!maxq.empty()) maxq.pop_front();
        // boundary case
        minq.push_back(make_pair(arr[i][0], 0));
        maxq.push_back(make_pair(arr[i][0], 0));
        res[i][0] = make_pair(arr[i][0], arr[i][0]);

        for (int j = 1; j < b; ++j) {
            // cout << "tag 4: " << j << endl;
            // increasing sequence from front to back
            while (!maxq.empty()) {
                if (arr[i][j] >= maxq.front().first || maxq.front().second <= j - n) maxq.pop_front();
                else break;             
            }
            maxq.push_front(make_pair(arr[i][j], j));

            // decreasing sequence from front to back
            while (!minq.empty()) {
                if (arr[i][j] <= minq.front().first || minq.front().second <= j - n) minq.pop_front();
                else break;
            }
            minq.push_front(make_pair(arr[i][j], j));

            while (!maxq.empty()) {
                if (maxq.back().second <= j - n) maxq.pop_back();
                else {
                    res[i][j].first = maxq.back().first;
                    break;
                }
            }
            while (!minq.empty()) {
                if (minq.back().second <= j - n) minq.pop_back();
                else {
                    res[i][j].second = minq.back().first;
                    break;
                }
            }
            assert(!maxq.empty());
            assert(!minq.empty());
        }
    }
    
    // cout << "tag 2" << endl;
    // second iteration by column, I am producing legacy code, sorry...
    for (int col = 0; col < b; ++col) {
        while(!minq.empty()) minq.pop_front();
        while(!maxq.empty()) maxq.pop_front();
        // boundary case
        minq.push_back(make_pair(res[0][col].second, 0));
        maxq.push_back(make_pair(res[0][col].first, 0));
        // res[0][col] = make_pair(arr[0][col], arr[0][col]);

        for (int row = 1; row < a; ++row) {
            // increasing sequence from front to back
            while (!maxq.empty()) {
                if (res[row][col].first > maxq.front().first || maxq.front().second <= row - n) maxq.pop_front();   
                else break;         
            }
            maxq.push_front(make_pair(res[row][col].first, row));

            // decreasing sequence from front to back
            while (!minq.empty()) {
                if (res[row][col].second < minq.front().first || minq.front().second <= row - n) minq.pop_front();
                else break;
            }
            minq.push_front(make_pair(res[row][col].second, row));

            while (!maxq.empty()) {
                if (maxq.back().second <= row - n) maxq.pop_back();
                else {
                    res[row][col].first = maxq.back().first;
                    break;
                }
            }
            while (!minq.empty()) {
                if (minq.back().second <= row - n) minq.pop_back();
                else {
                    res[row][col].second = minq.back().first;
                    break;
                }
            }
            assert(!maxq.empty());
            assert(!minq.empty());
        }
    }

    int ans = INT_MAX;
    // cout << "tag" << endl;
    for (int i = n - 1; i < a; ++i)
    for (int j = n - 1; j < b; ++j) {
        ans = min(ans, res[i][j].first - res[i][j].second);
    }
    printf("%d\n", ans);
    return 0;
}
