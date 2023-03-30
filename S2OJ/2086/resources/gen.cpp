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

#define N_TESTS 25
#define PERCENT_TESTS(_percent) (static_cast<double>(_percent) / 100 * N_TESTS)

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    int id = opt<int>("id");

    int min_n = 300,
        max_n = 500;
    int min_m = 300,
        max_m = 500;
    int min_e = 500,
        max_e = 5e4;

    if (id <= PERCENT_TESTS(50)) {
        min_n = 50, max_n = 100;
        min_m = 50, max_m = 100;
        min_e = 100, max_e = 5000;
    } else {  // all tests
        // (none)
    }

    int n = rnd.next(min_n, max_n);
    int m = rnd.next(min_m, max_m);
    int e = rnd.next(min_e, max_e);

    cout << n << ' ' << m << ' ' << e << endl;

    for (int i = 1; i <= e; i++) {
        int u = rnd.next(1, n);
        int v = rnd.next(1, m);

        cout << u << ' ' << v << endl;
    }

    return 0;
}
