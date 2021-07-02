#include <bits/stdc++.h>

using namespace std;

int n, k, a[1000005];
deque<int> q_min, q_max;
vector<int> ans_min, ans_max;

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; i++) {
        while (!q_max.empty() && a[q_max.back()] < a[i]) q_max.pop_back();
        while (!q_min.empty() && a[q_min.back()] > a[i]) q_min.pop_back();
        q_max.push_back(i);
        q_min.push_back(i);
        if (q_min.front() < i - k + 1) q_min.pop_front();
        if (q_max.front() < i - k + 1) q_max.pop_front();
        if (i >= k) {
            ans_max.push_back(a[q_max.front()]);
            ans_min.push_back(a[q_min.front()]);
        }
    }
    for (int i = 0; i < ans_min.size(); i++) {
        cout << ans_min[i] << ' ';
    }
    cout << endl;
    for (int i = 0; i < ans_max.size(); i++) {
        cout << ans_max[i] << ' ';
    }
    cout << endl;
    return 0;
}
