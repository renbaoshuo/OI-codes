#include <bits/stdc++.h>

using namespace std;

struct edge {
    int u, v;
};

vector<int>  e[100001];
vector<edge> s;
bool         vis_dfs[100001] = {0}, vis_bfs[100001] = {0};
vector<int>  ans_dfs, ans_bfs;

bool cmp(edge x, edge y) {
    if (x.v == y.v) {
        return x.u < y.u;
    }
    return x.v < y.v;
}

void dfs(int x) {
    vis_dfs[x] = 1;
    ans_dfs.push_back(x);
    for (int i = 0; i < e[x].size(); i++) {
        int point = s[e[x][i]].v;
        if (!vis_dfs[point]) {
            dfs(point);
        }
    }
}

void bfs(int x) {
    int        front, point;
    queue<int> q;
    vis_bfs[x] = true;
    q.push(x);
    ans_bfs.push_back(x);
    while (!q.empty()) {
        front = q.front();
        for (int i = 0; i < e[front].size(); i++) {
            point = s[e[front][i]].v;
            if (!vis_bfs[point]) {
                q.push(point);
                ans_bfs.push_back(point);
                vis_bfs[point] = true;
            }
        }
        q.pop();
    }
}

int main() {
    memset(vis_dfs, 0x00, sizeof(vis_dfs));
    memset(vis_bfs, 0x00, sizeof(vis_bfs));
    int n, m, uu, vv;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> uu >> vv;
        s.push_back({uu, vv});
    }
    sort(s.begin(), s.end(), cmp);
    for (int i = 0; i < m; i++) {
        e[s[i].u].push_back(i);
    }
    dfs(1);
    for (int i = 0; i < ans_dfs.size(); i++) {
        cout << ans_dfs[i] << ' ';
    }
    cout << endl;
    bfs(1);
    for (int i = 0; i < ans_bfs.size(); i++) {
        cout << ans_bfs[i] << ' ';
    }
    cout << endl;
    return 0;
}
