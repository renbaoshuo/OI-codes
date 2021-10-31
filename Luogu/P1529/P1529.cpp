#include <bits/stdc++.h>

using namespace std;

int p, w, dist[105];
char u, v;
bool vis[105];
vector<pair<int, int>> g[105];
pair<int, char> ans;
map<char, int> keymap;
map<int, char> rekeymap;

void dijkstra() {
    memset(dist, 0x3f, sizeof(dist));
    memset(vis, 0x00, sizeof(vis));
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    dist[keymap['Z']] = 0;
    q.push(make_pair(0, keymap['Z']));
    while (!q.empty()) {
        auto t = q.top();
        q.pop();
        if (vis[t.second]) continue;
        for (auto i : g[t.second]) {
            if (dist[i.first] > t.first + i.second) {
                dist[i.first] = t.first + i.second;
                q.push(make_pair(dist[i.first], i.first));
            }
        }
        vis[t.second] = true;
    }
}

int main() {
    cin >> p;
    for (int i = 1; i <= 26; i++) {
        keymap[i - 1 + 'a'] = i;
        rekeymap[i] = i - 1 + 'a';
        keymap[i - 1 + 'A'] = i + 26;
        rekeymap[i + 26] = i - 1 + 'A';
    }
    for (int i = 1; i <= p; i++) {
        cin >> u >> v >> w;
        g[keymap[u]].push_back(make_pair(keymap[v], w));
        g[keymap[v]].push_back(make_pair(keymap[u], w));
    }
    dijkstra();
    ans = make_pair(0x3f3f3f3f, 0);
    for (int i = keymap['A']; i < keymap['Z']; i++) {
        if (ans.first > dist[i]) {
            ans.first = dist[i];
            ans.second = rekeymap[i];
        }
    }
    cout << ans.second << ' ' << ans.first << endl;
    return 0;
}
