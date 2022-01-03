#include <bits/stdc++.h>

#include "head.h"

static inline unsigned int randnum() {
    static unsigned int seed = time(nullptr);
    return seed ^= seed << 5, seed ^= seed >> 7, seed ^= seed << 13;
}

std::string str = "1145141919810efghkkk";

signed main() {
    int n;
    std::cin >> n;
    unsigned int ps = (randnum() % str.length());
    if (!ps) ++ps;
    std::cout << str.substr(0, ps);
    for (int i = 1; i <= n; ++i) {
        unsigned int a = randnum(), b = randnum();
        unsigned int ret = solv(a, b);
        if (i == 1) std::cout << str.substr(ps) << '\n';
        std::cout << a * b << ' ' << ret << '\n';
    }
}
