#include <bits/stdc++.h>

using namespace std;

int n, a;

int main() {
    cin >> n;
    while (n--) {
        set<int> ans;
        cin >> a;
        for (int i = 1; i * i <= a; i++) {
            if (a % i == 0) {
                ans.insert(i);
                ans.insert(a / i);
            }
        }
        for (int i : ans) {
            cout << i << ' ';
        }
        cout << endl;
    }
    return 0;
}
