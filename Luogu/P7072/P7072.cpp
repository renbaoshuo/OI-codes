#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, w, t;
    vector<int> score;
    cin >> n >> w;
    for (int i = 1; i <= n; i++) {
        cin >> t;
        score.insert(lower_bound(score.begin(), score.end(), t), t);
        cout << score[score.size() - max(1, i * w / 100)] << ' ';
    }
    return 0;
}
