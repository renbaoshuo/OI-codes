#include <iostream>
#include <algorithm>

using std::cin;
using std::cout;
const char endl = '\n';

const unsigned long long mod = 1ull << 63,
                         mod_mask = mod - 1;

/**
 * Calculates the sum of i from 1 to x
 *
 * res = x * (x + 1) / 2
 */
unsigned long long sum_i_1(unsigned long long x) {
    unsigned long long t1 = x,
                       t2 = x + 1;

    if (x % 2 == 0) t1 /= 2;
    else t2 /= 2;

    return t1 * t2;
}

/**
 * Calculates the sum of i^2 from 1 to x
 *
 * res = x * (x + 1) * (2 * x + 1) / 6
 */
unsigned long long sum_i_2(unsigned long long x) {
    unsigned long long t1 = x,
                       t2 = x + 1,
                       t3 = x * 2 + 1;

    if (t1 % 2 == 0) t1 /= 2;
    else t2 /= 2;

    if (t1 % 3 == 0) t1 /= 3;
    else if (t2 % 3 == 0) t2 /= 3;
    else t3 /= 3;

    return t1 * t2 * t3;
}

/**
 * Calculates the sum of i^3 from 1 to x
 *
 * res = (x * (x + 1) / 2) * (x * (x + 1) / 2)
 */
unsigned long long sum_i_3(unsigned long long x) {
    return sum_i_1(x) * sum_i_1(x);
}

/**
 * Calculates this:
 *
 * @code
 * --#+
 *    |
 *    |
 * @endcode
 *
 * #: (2x + 1)^2
 */
unsigned long long calc_all(unsigned long long x) {
    if (x < 0) return 0;

    return sum_i_3(x) * 8 + sum_i_2(x) * 16 + sum_i_1(x) * 11 + (x + 1) * 3;
}

/**
 * Calculates this:
 *
 * @code
 * --#(+)
 *    (|)
 *    (|)
 * @endcode
 *
 * #: (2x + 1)^2
 * (): not included
 */
unsigned long long calc_top(unsigned long long x, unsigned long long y) {
    unsigned long long res = sum_i_2(y) * 8 + sum_i_1(y) * 6 + (y - x + 1) * (x + 2),
                       t = x + 1;

    if (x > 0) {
        res -= sum_i_2(x - 1) * 8 + sum_i_1(x - 1) * 6;
    }

    if (res % 2 == 0) res /= 2;
    else t /= 2;

    return res * t;
}

/**
 * Calculates this:
 *
 * @code
 * (--#)+
 *      |
 *      |
 * @endcode
 *
 * #: (2x + 1)^2
 * (): not included
 */
unsigned long long calc_right(unsigned long long x, unsigned long long y) {
    unsigned long long res = sum_i_2(x - 1) * 8 + sum_i_1(x - 1) * 10 + (x - y - 1) * (4 - y),
                       t = y + 1;

    if (y > 0) {
        res -= sum_i_2(y) * 8 + sum_i_1(y) * 10;
    }

    if (res % 2 == 0) res /= 2;
    else t /= 2;

    return res * t;
}

unsigned long long calc(long long x, long long y) {
    if (x < 0 || y < 0) return 0;

    if (x - 1 <= y) {
        return calc_all(x - 1) + calc_top(x, y);
    }

    // x - 1 > y
    return calc_all(y) + calc_right(x, y);
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;

    cin >> q;

    while (q--) {
        long long x1, x2, y1, y2;

        cin >> x1 >> x2 >> y1 >> y2;

        cout << ((calc(x2, y2) - calc(x1 - 1, y2) - calc(x2, y1 - 1) + calc(x1 - 1, y1 - 1)) & mod_mask) << endl;
    }

    return 0;
}
