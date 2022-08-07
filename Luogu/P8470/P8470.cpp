#include <iostream>
#include <map>

using std::cin;
using std::cout;
const char endl = '\n';

const int dx[] = {0, 1, 0, -1},
          dy[] = {1, 0, -1, 0};

int n, x, y;
unsigned long long z;
std::map<int, std::map<int, unsigned long long>> map;
unsigned long long sum;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    while (n--) {
        cin >> x >> y >> z;

        auto cur = map[x][y];  // 当前值

        for (int i = 0; i < 4; i++) {
            const int xx = x + dx[i], yy = y + dy[i];

            if (!map.count(xx) || !map[xx].count(yy)) continue;

            auto t = map[xx][yy];

            if (cur < t) {
                if (cur + z >= t) {
                    sum -= (t - cur) * 2;
                } else {
                    sum -= z * 2;
                }
            }
        }

        sum += z * 4;    // 四个侧面
        map[x][y] += z;  // 更新高度

        cout << sum << endl;
    }

    return 0;
}
