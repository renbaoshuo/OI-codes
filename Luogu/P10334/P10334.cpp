#include <iostream>
#include <stack>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 2e5 + 5;

int n, t[N], a[N];
std::stack<int> st;
long long ans;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> t[i];
    }

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++) {
        if (t[i] < i) {
            cout << -1 << endl;  // 无解

            exit(0);  // 退出程序
        }
    }

    int now = n;  // 记录做到的杯号

    // 枚举每一个时间点
    for (int i = t[n]; i; i--) {
        if (t[now] == i) {  // 当前时间有人来取饮料，先给他制作
            if (!st.empty()) {
                // 注意当前所制作饮料不能小于后面提前制作的饮料（因为要保证提前制作的饮料不会被抢走）
                st.emplace(std::max(st.top(), a[now]));
            } else {
                st.emplace(a[now]);
            }

            // 准备制作下一杯饮料（编号靠前的）
            // 需要在前面找时间做这杯饮料
            now--, i++;
        } else if (t[now] < i) {
            // 这个人在此之前取饮料，所以不用管它
            // 当前时间就可以用来做后面需要提前制作的饮料
            if (!st.empty()) {
                ans += st.top();
                st.pop();
            }
        } else {  // t[now] > i
            // 这个人取饮料的时间在此之后，也就是说他需要提前制作饮料
            now--, i++;
        }
    }

    while (!st.empty()) {  // 把剩余的做完
        ans += st.top();
        st.pop();
    }

    cout << ans << endl;

    return 0;
}
