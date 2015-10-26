#include <stdio.h>
#include <algorithm>
#include <map>
using namespace std;
int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    char x, y;
    int arr[26];
    for (int i = 0; i < 26; ++i) arr[i] = i;
    char name[200005];
    scanf("%s", name);
    for (int i = 0; i < m; ++i) {
        scanf(" %c %c", &x, &y);
        if (x != y) swap(arr[x - 'a'], arr[y - 'a']);
    }
    map<char, char> mp;
    for (int i = 0; i < 26; ++i) {
        x = (char)(arr[i] + 'a');
        y = (char)(i + 'a');
        mp[x] = y;
    }
    for (int i = 0; i < n; ++i) {
        name[i] = mp[name[i]];
    }
    printf("%s\n", name);
    return 0;
}
