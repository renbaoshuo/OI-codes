#include <bits/stdc++.h>

using namespace std;

int n, m, lx, ly, rx, ry;
pair<int, int> point[1005];

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> point[i].first >> point[i].second;
    }
    for (int i = 0; i < m; i++) {
        cin >> lx >> ly >> rx >> ry;
        for (int i = 0; i < n; i++) {
            if (lx <= point[i].first && point[i].first <= rx && ly <= point[i].second && point[i].second <= ry) {
                cout << "Yes" << endl;
                exit(0);
            }
        }
    }
    cout << "No" << endl;
    return 0;
}
