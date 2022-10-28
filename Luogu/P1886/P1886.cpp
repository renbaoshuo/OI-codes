#include <iostream>
#include <deque>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e6 + 5;

int n, k, a[N];
std::deque<int> q_min, q_max;
std::vector<int> ans_min, ans_max;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++) {
        while (!q_min.empty() && a[q_min.back()] > a[i]) q_min.pop_back();
        while (!q_max.empty() && a[q_max.back()] < a[i]) q_max.pop_back();

        q_min.emplace_back(i);
        q_max.emplace_back(i);

        if (q_min.front() < i - k + 1) q_min.pop_front();
        if (q_max.front() < i - k + 1) q_max.pop_front();

        if (i >= k) {
            ans_min.emplace_back(a[q_min.front()]);
            ans_max.emplace_back(a[q_max.front()]);
        }
    }

    for (int x : ans_min) {
        cout << x << ' ';
    }

    cout << endl;

    for (int x : ans_max) {
        cout << x << ' ';
    }

    cout << endl;

    return 0;
}
