#include "testlib.h"
#include <bits/stdc++.h>

using ui = unsigned int;

signed main(int argc, char** argv) {
	registerTestlibCmd(argc, argv);

	int n = inf.readInt();
	for (int i = 1; i <= n; ++i) {
		ui x = ui(ouf.readLong()), y = ui(ouf.readLong());
		if (x != y) {
			quitp(1.0 * (i - 1) / n, "jury's anwser is %u, but your answer is %u", x, y);
		}
	}
	quitf(_ok, "Accept!");
}
