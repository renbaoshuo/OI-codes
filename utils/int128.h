#include <algorithm>
#include <ostream>
#include <string>

/**
 * Prints an 128-bit integer to an output stream.
 */
std::ostream& operator<<(std::ostream& __ostream, __int128 __n) {
    std::string __o;

    if (__n == 0) {
        return __ostream << 0;
    }

    bool is_negative = false;

    if (__n < 0) {
        is_negative = true;
        __n = -__n;
    }

    while (__n) {
        __o.push_back(__n % 10 + '0');
        __n /= 10;
    }

    std::reverse(__o.begin(), __o.end());

    if (is_negative) {
        __ostream << '-';
    }

    return __ostream << __o;
}
