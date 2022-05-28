// 一般用于函数式交互 
#include "head.h"
#include <bits/stdc++.h>

#define ui unsigned int

static inline ui randnum() {
	static ui seed = time(nullptr);
	return seed ^= seed << 5, seed ^= seed >> 7, seed ^= seed << 13;
}
std::string str = "1145141919810efghkkk";

signed main() {
	int n;
	std::cin >> n;
	ui ps = (randnum() % str.length());
	if (!ps) ++ps;
	std::cout << str.substr(0, ps);
	for (int i = 1; i <= n; ++i) {
		ui a = randnum(), b = randnum();
		ui ret = solv(a, b);
		if (i == 1) std::cout << str.substr(ps) << '\n';
		std::cout << a * b << ' ' << ret << '\n';
	}
}
