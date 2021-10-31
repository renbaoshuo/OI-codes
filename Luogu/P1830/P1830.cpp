#include <bits/stdc++.h>

using namespace std;

pair<int, int> boom[105][105];

int main() {
    int n, m, x, y, x1, y1, x2, y2;
    cin >> n >> m >> x >> y;
    for (int i = 1; i <= x; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        for (int j = x1; j <= x2; j++) {
            for (int k = y1; k <= y2; k++) {
                boom[j][k].first++;
                boom[j][k].second = i;
            }
        }
    }
    for (int i = 1; i <= y; i++) {
        cin >> x1 >> y1;
        if (boom[x1][y1].first) {
            cout << "Y " << boom[x1][y1].first << ' ' << boom[x1][y1].second << endl;
        } else {
            cout << "N" << endl;
        }
    }
    return 0;
}
