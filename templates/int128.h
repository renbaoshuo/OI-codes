#include <algorithm>
#include <ostream>
#include <string>

std::ostream& operator<<(std::ostream& __ostream, __int128 __n) {
    std::string __o;
    while (__n) {
        __o.push_back(__n % 10 + '0');
        __n /= 10;
    }
    std::reverse(__o.begin(), __o.end());
    return __ostream << __o;
}
