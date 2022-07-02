#include <cstdio>
#include <vector>

const int N = 15;

int n, a[N][N];
long long ans;

const int dx[] = {0, 1, 0, -1, 0, 1, 1, -1, -1},
          dy[] = {0, 0, -1, 0, 1, 1, -1, 1, -1};

std::vector<int> res;

void dfs(int x, int y, int k, int cnt, long long sum, std::vector<int> s) {
    if (x > n) x = 1;
    if (x < 1) x = n;
    if (y > n) y = 1;
    if (y < 1) y = n;

    if (cnt == n) {
        if (sum > ans) {
            ans = sum;
            res = s;
        }

        return;
    }

    s.push_back(a[x][y]);

    dfs(x + dx[k], y + dy[k], k, cnt + 1, sum * 10 + a[x][y], s);
}

int main() {
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%1d", &a[i][j]);
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= 8; k++) {
                dfs(i, j, k, 0, 0, std::vector<int>());
            }
        }
    }

    for (const int &x : res) {
        printf("%d", x);
    }
    printf("\n");

    return 0;
}
