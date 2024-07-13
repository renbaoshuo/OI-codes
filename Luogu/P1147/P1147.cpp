#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

int m;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> m;

    // 为什么到 m/2 结束？因为 m/2 之后的数不可能连着取两个数之和等于 m。
    for (int i = 1, j = 2, sum = 3 /* 初始 1 + 2 = 3 */; i <= (m >> 1);) {
        if (sum == m) {  // 够了，输出答案，并且把左面的数从窗口中删去
            cout << i << ' ' << j << endl;
            sum -= i++;        // 压行：sum -= i; i++;
        } else if (sum < m) {  // 不够，需要往后再取一个数
            sum += ++j;        // 压行：j++; sum += j;  # 注意：这里是先加 j 再加 sum，顺序要写对
        } else {               // sum > m    # 多了，把左面的数从窗口中删去
            sum -= i++;        // 压行：sum -= i; i++;
        }
    }

    return 0;
}
