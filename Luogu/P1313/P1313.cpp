#include <iostream>
#include <array>
#include <type_traits>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1005;
const int mod = 1e4 + 7;

template <int x>
using number = std::integral_constant<int, x>;

template <int n>
struct factorial : number<static_cast<long long>(n) * factorial<n - 1>::value % mod> {};

template <>
struct factorial<0> : number<1> {};

template <int... S>
constexpr std::array<int, sizeof...(S)> get_factorial_table_impl(std::integer_sequence<int, S...>) {
    return {factorial<S>::value...};
}

template <int S>
constexpr auto get_factorial_table() {
    return get_factorial_table_impl(std::make_integer_sequence<int, S>{});
}

template <int n>
struct inverse : number<static_cast<long long>(mod - (mod / n)) * inverse<mod % n>::value % mod> {};

template <>
struct inverse<1> : number<1> {};

template <>
struct inverse<0> : number<1> {};

template <int n>
struct factorial_inverse : number<static_cast<long long>(factorial_inverse<n - 1>::value) * inverse<n>::value % mod> {};

template <>
struct factorial_inverse<1> : number<1> {};

template <>
struct factorial_inverse<0> : number<1> {};

template <int... S>
constexpr std::array<int, sizeof...(S)> get_factorial_inverse_table_impl(std::integer_sequence<int, S...>) {
    return {factorial_inverse<S>::value...};
}

template <int S>
constexpr auto get_factorial_inverse_table() {
    return get_factorial_inverse_table_impl(std::make_integer_sequence<int, S>{});
}

int a, b, k, n, m;

constexpr auto fac = get_factorial_table<N>(),
               inv = get_factorial_inverse_table<N>();

int binpow(int a, int b) {
    int res = 1;
    a %= mod;
    while (b) {
        if (b & 1) res = 1ll * res * a % mod;
        a = 1ll * a * a % mod;
        b >>= 1;
    }
    return res;
}

inline int C(int n, int m) {
    return 1ll * fac[n] * inv[m] % mod * inv[n - m] % mod;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> a >> b >> k >> n >> m;

    cout << static_cast<long long>(C(k, n)) * binpow(a, n) % mod * binpow(b, m) % mod << endl;

    return 0;
}
