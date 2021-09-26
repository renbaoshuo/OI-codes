#include <bits/stdc++.h>

using namespace std;

int n, k, p, trie[10000005][2], size[10000005];
char s[100005];
bool a[100005];

void calcsize(int u) {
    if (trie[u][0]) calcsize(trie[u][0]);
    if (trie[u][1]) calcsize(trie[u][1]);
    size[u] += size[trie[u][0]] + size[trie[u][1]];
}

void print(int u, int k) {
    if (u != 1 && k-- == 1) {
        cout << endl;
        exit(0);
    }
    if (size[trie[u][0]] >= k) {
        cout << 0;
        print(trie[u][0], k);
    } else {
        cout << 1;
        print(trie[u][1], k - size[trie[u][0]]);
    }
}

int main() {
    cin >> n >> k >> s + 1;
    for (int i = 1; i <= n; i++) {
        a[i] = s[i] - '0';
    }
    p = 1;
    for (int i = 1; i <= n; i++) {
        int u = 1;
        for (int j = i; j <= min(n, i + k - 1); j++) {
            size[u = (trie[u][a[j]] ? trie[u][a[j]] : trie[u][a[j]] = ++p)] = 1;
        }
    }
    calcsize(1);
    print(1, k);
    return 0;
}
