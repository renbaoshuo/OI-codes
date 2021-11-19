#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, t, max_score = -0x3f3f3f3f;
    int scores[1005];
    string s, max_player, players[1005];
    map<string, int> m, m1;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> players[i] >> scores[i];
        m[players[i]] += scores[i];
    }
    for (int i = 0; i < n; i++) {
        max_score = max(max_score, m[players[i]]);
    }
    for (int i = 0; i < n; i++) {
        m1[players[i]] += scores[i];
        if (m[players[i]] == max_score && m1[players[i]] >= max_score) {
            max_player = players[i];
            break;
        }
    }
    cout << max_player << endl;
    return 0;
}
