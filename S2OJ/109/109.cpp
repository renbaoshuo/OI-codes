#include <bits/stdc++.h>

using namespace std;

int n, m, s, x, y;

struct node {
    int depth, father;
    vector<int> next;
} tree[500005];
bool vis[500005];

void dfs(int depth, int root, int father) {
    tree[root].father = father;
    for (int i = 0; i < tree[root].next.size(); i++) {
        if (tree[root].next[i] != father) {
            tree[tree[root].next[i]].depth = depth + 1;
            tree[tree[root].next[i]].father = root;
            dfs(depth + 1, tree[root].next[i], root);
        }
    }
    return;
}

void dfs2(int now) {
    vis[now] = true;
    if(now == s) return;
    else dfs2(tree[now].father);
}

int dfs3(int now) {
    if(vis[now]) return now;
    else return dfs3(tree[now].father);
}

int main() {
    scanf("%d%d%d", &n, &m, &s);
    for (int i = 1; i < n; i++) {
        scanf("%d%d", &x, &y);
        tree[x].next.push_back(y);
        tree[y].next.push_back(x);
    }
    dfs(1, s, s);
    for(int i = 0 ; i < m ; i++) {
        scanf("%d%d", &x, &y);
        memset(vis, 0x00, sizeof(vis));
        if(tree[x].depth > tree[y].depth) {
            dfs2(x);
            printf("%d\n", dfs3(y));
        } else {
            dfs2(y);
            printf("%d\n", dfs3(x));
        }
    }
    return 0;
}
