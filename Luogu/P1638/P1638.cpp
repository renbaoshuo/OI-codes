#include <iostream>
#include <limits>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e6 + 5,
          M = 2e3 + 5;

int n, m, a[N];
int cnt, b[M];  // 记录出现过的数
int ans, ans_l, ans_r;

void insert(int x) {
    if (b[x] == 0) cnt++;  // 维护数的数目
    b[x]++;                // 维护数的出现次数
}

void erase(int x) {
    b[x]--;                // 维护数的出现次数
    if (b[x] == 0) cnt--;  // 维护数的数目
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    ans = std::numeric_limits<int>::max();

    for (int i = 1, j = 1; i <= n; i++) {
        insert(a[i]);  // 先维护右指针

        while (true) {
            erase(a[j]);

            if (cnt == m) {  // 删了以后还是满足条件
                j++;         // 维护左指针
            } else {
                insert(a[j]);  // 恢复
                break;
            }
        }

        if (cnt == m && i - j + 1 < ans) {  // 记录答案
            ans = i - j + 1;
            ans_l = j;
            ans_r = i;
        }
    }

    cout << ans_l << ' ' << ans_r << endl;

    return 0;
}
