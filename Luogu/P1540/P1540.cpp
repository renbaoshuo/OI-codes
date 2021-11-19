// R38909558

#include <bits/stdc++.h>

using namespace std;

int main() {
    int m, n, t, f = 0, ans = 0;
    bool flag = false;
    vector<int> memory;
    queue<int> mq;
    cin >> m >> n;
    for (int i = 0; i < n; i++) {
        cin >> t;
        ans++;
        flag = false;
        for (int j = f; j < memory.size(); j++) {
            if (memory[j] == t) {
                ans--;
                flag = true;
            }
        }
        if (!flag) {
            memory.push_back(t);
            mq.push(t);
        }
        if (mq.size() > m) {
            f++;
            mq.pop();
        }
    }
    cout << ans << endl;
    return 0;
}
