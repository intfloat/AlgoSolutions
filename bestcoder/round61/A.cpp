#include <stdio.h>
#include <iostream>
using namespace std;
int main() {
    int N, S, T;
    while (cin >> N >> S >> T) {
        if (N == 1) printf("0\n");
        else if (N > 1 && S == T) printf("-1\n");
        else if (S == 1 && T == N) printf("0\n");
        else if (S == N && T == 1) printf("0\n");
        else if (S == 1 || S == N) printf("1\n");
        else if (S + 1 == T || T + 1 == S) printf("1\n");
        else printf("2\n");
    }
    return 0;
}
