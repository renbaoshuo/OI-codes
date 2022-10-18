#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 5e5 + 5;

int n, a[N], val, pre[N], suf[N];
std::vector<int> ans;
std::stack<int> st_pre, st_suf;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++) {
        while (!st_pre.empty() && a[st_pre.top()] % a[i] == 0) st_pre.pop();
        pre[i] = i - (st_pre.empty() ? 0 : st_pre.top()) - 1;
        st_pre.emplace(i);
    }

    for (int i = n; i; i--) {
        while (!st_suf.empty() && a[st_suf.top()] % a[i] == 0) st_suf.pop();
        suf[i] = (st_suf.empty() ? n + 1 : st_suf.top()) - i - 1;
        st_suf.emplace(i);
    }

    for (int i = 1; i <= n; i++) {
        val = std::max(val, pre[i] + suf[i]);
    }

    for (int i = 1; i <= n; i++) {
        if (pre[i] + suf[i] == val) {
            ans.emplace_back(i - pre[i]);
        }
    }

    std::sort(ans.begin(), ans.end());
    ans.erase(std::unique(ans.begin(), ans.end()), ans.end());

    cout << ans.size() << ' ' << val << endl;

    for (int x : ans) {
        cout << x << ' ';
    }

    cout << endl;

    return 0;
}
