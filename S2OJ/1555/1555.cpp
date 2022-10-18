#include <iostream>
#include <algorithm>
#include <complex>
#include <string>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

using complex = std::complex<long long>;

complex to_complex(std::string str) {
    complex res{0ll, 0ll};

    if (str.empty()) return res;

    if (str[0] == '-') {
        auto pos_pos = str.find('+', 1),
             pos_neg = str.find('-', 1);

        if (pos_pos == std::string::npos && pos_neg == std::string::npos) {
            // 仅实部 or 仅虚部

            if (str.back() == 'i') {
                // 仅虚部

                auto str_imag = str.substr(1, str.size() - 2);

                res.imag(-std::stoll(str_imag.empty() ? "1" : str_imag));
            } else {
                // 仅实部

                res.real(-std::stoll(str.substr(1)));
            }
        } else if (pos_pos == std::string::npos) {
            // 虚部是负数

            auto str_real = str.substr(1, pos_neg - 1),
                 str_imag = str.substr(pos_neg + 1, str.size() - 1 - (pos_neg + 1));

            res.real(-std::stoll(str_real));
            res.imag(-std::stoll(str_imag.empty() ? "1" : str_imag));
        } else {
            // 虚部是正数

            auto str_real = str.substr(1, pos_pos - 1),
                 str_imag = str.substr(pos_pos + 1, str.size() - 1 - (pos_pos + 1));

            res.real(-std::stoll(str_real));
            res.imag(std::stoll(str_imag.empty() ? "1" : str_imag));
        }
    } else {
        auto pos_pos = str.find('+', 1),
             pos_neg = str.find('-', 1);

        if (pos_pos == std::string::npos && pos_neg == std::string::npos) {
            // 仅实部 or 仅虚部

            if (str.back() == 'i') {
                // 仅虚部

                auto str_imag = str.substr(0, str.size() - 1);

                res.imag(std::stoll(str_imag.empty() ? "1" : str_imag));
            } else {
                // 仅实部

                res.real(std::stoll(str));
            }
        } else if (pos_pos == std::string::npos) {
            // 虚部是负数

            auto str_real = str.substr(0, pos_neg),
                 str_imag = str.substr(pos_neg + 1, str.size() - 1 - (pos_neg + 1));

            res.real(std::stoll(str_real));
            res.imag(-std::stoll(str_imag.empty() ? "1" : str_imag));
        } else {
            // 虚部是正数

            auto str_real = str.substr(0, pos_pos),
                 str_imag = str.substr(pos_pos + 1, str.size() - 1 - (pos_pos + 1));

            res.real(std::stoll(str_real));
            res.imag(std::stoll(str_imag.empty() ? "1" : str_imag));
        }
    }

    return res;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    std::string s;

    cin >> s;

    auto num = to_complex(s);
    std::vector<bool> ans;

    while (num.real() || num.imag()) {
        bool r = (num.real() + num.imag()) % 2;

        ans.emplace_back(r);

        long long q_r = (num.real() - r - num.imag()) / -2;
        long long q_i = q_r - num.imag();

        num.real(q_r);
        num.imag(q_i);
    }

    if (ans.empty()) ans.emplace_back(0);

    std::reverse(ans.begin(), ans.end());

    for (auto x : ans) {
        cout << x;
    }

    cout << endl;

    return 0;
}
