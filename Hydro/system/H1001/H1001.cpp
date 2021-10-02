#include <bits/stdc++.h>

using namespace std;

int n, p = 1, trie[10000005][26], size[10000005];
char s[4000005];

void insert(int u, const char* s) {
    if (!strlen(s)) {
        size[u] = 1;
        return;
    }
    if (!trie[u][s[0] - 'a']) trie[u][s[0] - 'a'] = ++p;
    insert(trie[u][s[0] - 'a'], s + 1);
}

void calcsize(int u) {
    for (int i = 0; i < 26; i++) {
        if (trie[u][i]) {
            calcsize(trie[u][i]);
            size[u] += size[trie[u][i]];
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%s", s);
        insert(1, s);
    }
    calcsize(1);
    printf("%d\n", size[1]);
    return 0;
}
