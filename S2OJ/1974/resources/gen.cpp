/**
 * @file S2OJ/1974/gen.cpp
 * @author Baoshuo <i@baoshuo.ren>
 * @url https://baoshuo.ren
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

    int min_n = 100000,
        max_n = 100000;  // 1e5
    int min_m = 100000,
        max_m = 100000;  // 1e5

    std::cerr << PERCENT_TESTS(30) << endl;

    if (id <= PERCENT_TESTS(30)) {
        min_n = max_n = 10;
        min_m = max_m = 10;
    } else if (id <= PERCENT_TESTS(70)) {
        min_n = max_n = 1000;
        min_m = max_m = 1000;
    } else {  // all tests
        // (none)
    }

    int n = rnd.next(min_n, max_n);
    int m = rnd.next(min_m, max_m);

    cout << n << ' ' << m << endl;

    for (int i = 1; i <= n; i++) {
        const char end_c = i < n ? ' ' : '\n';

        cout << rnd.next(std::numeric_limits<int>::min(), std::numeric_limits<int>::max()) << end_c;
    }

    for (int i = 1; i <= m; i++) {
        int op = rnd.next(1, 2);

        if (op == 1) {
            int x = rnd.next(1, n);
            int y = rnd.next(1, n);

            cout << op << ' ' << x << ' ' << y << endl;
        } else {
            int x = rnd.next(1, n);

            cout << op << ' ' << x << endl;
        }
    }

    return 0;
}
