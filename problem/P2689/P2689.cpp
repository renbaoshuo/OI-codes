#include<bits/stdc++.h>

using namespace std;

int main() {
    int x1, y1, x2, y2, t, ans = 0;
    char c;
    cin >> x1 >> y1 >> x2 >> y2 >> t;
    for(int i = 1 ; i <= t ; i++) {
        cin >> c;
        if(c == 'E' && y1 < y2) {
            y1++;
            ans++;
        }
        else if(c == 'W' && y1 > y2) {
            y1--;
            ans++;
        }
        else if(c == 'N' && x1 < x2) {
            x1++;
            ans++;
        }
        else if(c == 'S' && x1 > x2) {
            x1--;
            ans++;
        }
        if(x1 == x2 && y1 == y2) {
            cout << ans << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}
