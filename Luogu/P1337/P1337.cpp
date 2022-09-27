#include <iostream>
#include <chrono>
#include <cmath>
#include <iomanip>
#include <random>
#include <tuple>
#include <utility>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;

    cin >> n;

    std::vector<std::tuple<int, int, int>> a(n);

    for (auto &o : a) {
        cin >> std::get<0>(o) >> std::get<1>(o) >> std::get<2>(o);
    }

    std::mt19937 gen(std::chrono::system_clock::now().time_since_epoch().count());

    auto random = [&](int low, int high) -> int {
        std::uniform_int_distribution<> dist(low, high);
        return dist(gen);
    };

    auto potential_energy = [&](double x, double y) -> double {
        double res = 0;

        for (auto &o : a) {
            double xx = x - std::get<0>(o),
                   yy = y - std::get<1>(o);

            res += std::sqrt(std::pow(xx, 2) + std::pow(yy, 2)) * std::get<2>(o);
        }

        return res;
    };

    double ans_x = 0,
           ans_y = 0,
           ans = 1e18;

    for (int i = 1; i <= 10; i++) {
        double xx = ans_x,
               yy = ans_y;

        double t = 21000;

        while (t > 1e-15) {
            double tmp_x = ans_x + random(-100000, 100000) * t,
                   tmp_y = ans_y + random(-100000, 100000) * t;

            double tmp_ans = potential_energy(tmp_x, tmp_y);
            double delta = tmp_ans - ans;

            if (delta < 0) {
                ans_x = xx = tmp_x;
                ans_y = yy = tmp_y;
                ans = tmp_ans;
            } else if (std::exp(-delta / t) * 10000 > random(0, 10000)) {
                xx = tmp_x;
                yy = tmp_y;
            }

            t *= 0.998;
        }
    }

    cout << std::fixed << std::setprecision(3) << ans_x << ' '
         << std::fixed << std::setprecision(3) << ans_y << endl;

    return 0;
}
