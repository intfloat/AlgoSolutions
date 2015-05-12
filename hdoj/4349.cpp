#include <iostream>
using namespace std;
int main() {
    int N;
    while (cin >> N)
        cout << (1 << __builtin_popcount(N)) << endl;
    return 0;
}
