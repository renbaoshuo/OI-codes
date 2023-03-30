/**
 * @file S2OJ/1991/gen.cpp
 * @author Baoshuo <i@baoshuo.ren>
 * @url https://baoshuo.ren
 * @license GPL-3.0
 * @date 2023-03-30
 */

#include "testlib.h"

#include <iostream>
#include <limits>

using std::cin;
using std::cout;
const char endl = '\n';

#define N_TESTS 20
#define PERCENT_TESTS(_percent) (static_cast<double>(_percent) / 100 * N_TESTS)

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    int id = opt<int>("id");

    int min_n = 10000,
        max_n = 10000;  // 1e4
    int min_m = 10000,
        max_m = 10000;  // 1e4

    if (id <= PERCENT_TESTS(50)) {
        min_n = max_n = 100;
        min_m = max_m = 100;
    } else {  // all tests
        // (none)
    }

    int n = rnd.next(min_n, max_n);
    int m = rnd.next(min_m, max_m);

    cout << n << ' ' << m << endl;

    for (int i = 1; i <= n; i++) {
        const char end_c = i < n ? ' ' : '\n';

        cout << rnd.next(0, 1000) << end_c;
    }

    for (int i = 1; i <= m; i++) {
        int u = rnd.next(1, n);
        int v = rnd.next(1, n);

        cout << u << ' ' << v << endl;
    }

    return 0;
}
