#include <cstdio>
#include <cctype>
#include <cstring>
#include <stack>

const int N = 4e6 + 5;

template <typename T>
void read(T &x) {
    x = 0;
    T sig = 1;
    char c = getchar();

    for (; !isdigit(c); c = getchar()) {
        if (c == '-') sig = -1;
    }

    for (; isdigit(c); c = getchar()) {
        x = (x << 1) + (x << 3) + c - '0';
    }

    x *= sig;
}

int n, a[N];
long long ans_min[N], ans_max[N], ans = -1;
std::stack<long long> st_min, st_max;

int main() {
    read(n);

    for (int i = 1; i <= n; i++) {
        read(a[i]);
    }

    memset(ans_min, 0x3f, sizeof(ans_min));

    for (int i = 1; i <= n; i++) {
        while (!st_max.empty() && a[st_max.top()] > a[i]) {
            auto x = ans_max[st_max.top()];
            ans = std::max(ans, x - a[i] - i - 1);
            ans_max[i] = std::max(ans_max[i], x);
            st_max.pop();
        }
        st_max.push(i);
        ans_max[i] = std::max(ans_max[i], static_cast<long long>(a[i]) + i);
    }

    for (int i = 1; i <= n; i++) {
        while (!st_min.empty() && a[st_min.top()] < a[i]) {
            auto x = ans_min[st_min.top()];
            ans = std::max(ans, static_cast<long long>(a[i]) - i - x - 1);
            ans_min[i] = std::min(ans_min[i], x);
            st_min.pop();
        }
        st_min.push(i);
        ans_min[i] = std::min(ans_min[i], static_cast<long long>(a[i]) - i);
    }

    printf("%lld\n", ans);

    return 0;
}
