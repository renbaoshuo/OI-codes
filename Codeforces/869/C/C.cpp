#include <iostream>
#include <array>
#include <type_traits>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 5005;
const int mod = 998244353;

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

int a, b, c, ab, ac, bc, ans;

constexpr auto fac = get_factorial_table<N>(),
               fac_inv = get_factorial_inverse_table<N>();

inline int C(int n, int m) {
    return static_cast<long long>(fac[n]) * fac_inv[m] % mod * fac_inv[n - m] % mod;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> a >> b >> c;

    for (int i = 0; i <= std::min(a, b); i++) {
        ab = (ab + static_cast<long long>(C(a, i)) * C(b, i) % mod * fac[i] % mod) % mod;
    }

    for (int i = 0; i <= std::min(a, c); i++) {
        ac = (ac + static_cast<long long>(C(a, i)) * C(c, i) % mod * fac[i] % mod) % mod;
    }

    for (int i = 0; i <= std::min(b, c); i++) {
        bc = (bc + static_cast<long long>(C(b, i)) * C(c, i) % mod * fac[i] % mod) % mod;
    }

    cout << (((static_cast<long long>(ab) * ac) % mod * bc) % mod) % mod << endl;

    return 0;
}
