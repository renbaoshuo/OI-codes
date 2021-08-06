#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string a, b;
        cin >> a >> b;
        int as = a.size();
        int bs = b.size();
        if (as - bs == 3 || as - bs == -1 || as - bs == -2) {
            cout << "Player1" << endl;
        } else if (a == b) {
            cout << "Tie" << endl;
        } else {
            cout << "Player2" << endl;
        }
    }
    return 0;
}
