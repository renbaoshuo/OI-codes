#include "interaction.h"

inline int solve(int i) {
	int l = 0, r = 1000000;
	while (l < r) {
		int mid = l + (r - l) / 2;
		if (guess(i, mid) >= 0) r = mid;
		else l = mid + 1;
	}
	return l;
}

int main() {
	int n = get_num();
	std::vector<int> a(n);
	for (int i = 0; i < n; i++) {
		a[i] = solve(i);
	}

	submit(a);
}
