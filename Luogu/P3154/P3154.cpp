#include <cstdio>
#include <cctype>

const int N = 10;

int n, a[N], s[N], ans;

template <typename T>
void read(T& x) {
    x = 0;
    char c = getchar();
    int f = 1;

    while (!isdigit(c)) {
        if (c == '-') f = -1;
        c = getchar();
    }

    while (isdigit(c)) {
        x = x * 10 + (c - '0');
        c = getchar();
    }

    x *= f;
}

void dfs(int x, int y) {
    // 当前得分已经大于最终得分
    if (s[x] > a[x]) return;

    // 如果以后的比赛全赢也小于最后的分数
    if (s[x] + (n - y + 1) * 3 < a[x]) return;

    if (x == n && s[x] == a[x]) {
        ans++;
        return;
    }

    if (y == n) {
        int t = a[x] - s[x];

        // 最后一场比赛无法凑出 2 分
        switch (t) {
            case 0: {
                s[y] += 3;
                dfs(x + 1, x + 2);
                s[y] -= 3;

                break;
            }

            case 1: {
                s[x] += 1;
                s[y] += 1;
                dfs(x + 1, x + 2);
                s[x] -= 1;
                s[y] -= 1;

                break;
            }

            case 3: {
                s[x] += 3;
                dfs(x + 1, x + 2);
                s[x] -= 3;

                break;
            }
        }

        return;
    }

    // x 胜
    s[x] += 3;
    s[y] += 0;
    dfs(x, y + 1);
    s[x] -= 3;
    s[y] -= 0;

    // 平局
    s[x] += 1;
    s[y] += 1;
    dfs(x, y + 1);
    s[x] -= 1;
    s[y] -= 1;

    // y 胜
    s[x] += 0;
    s[y] += 3;
    dfs(x, y + 1);
    s[x] -= 0;
    s[y] -= 3;
}

int main() {
    read(n);

    for (int i = 1; i <= n; i++) {
        read(a[i]);
    }

    dfs(1, 2);

    printf("%d\n", ans);

    return 0;
}
