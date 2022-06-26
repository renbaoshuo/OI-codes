#include <iostream>
#include <string>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e7 + 5;

int p[N << 1], mid, r, ans;
std::string s1, s2;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> s1;

    // 使字符串的长度变为 (2n + 1)，方便处理
    s2.push_back('^');
    for (const char &c : s1) {
        s2.push_back('#');
        s2.push_back(c);
    }
    s2 += "#$";

    for (int i = 1; i < s2.size(); i++) {
        // r 代表以 mid 为中心的最长回文子串的右边界
        p[i] = i < r
                 // mid * 2 - i 为 i 关于 mid 的对称点
                 ? std::min(p[mid * 2 - i], r - i)
                 // 超过边界就不是回文串了
                 : 1;

        // 扩展回文串长度
        while (s2[i - p[i]] == s2[i + p[i]]) p[i]++;

        // 扩展右边界
        if (r < i + p[i]) {
            r = i + p[i];
            mid = i;
        }
    }

    for (int i = 0; i < s2.size(); i++) {
        ans = std::max(ans, p[i] - 1);  // p[i] - 1 即为以 i 为中心的最长的回文子串长度
    }

    cout << ans << endl;

    return 0;
}
