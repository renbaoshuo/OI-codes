#include <cstdlib>
#include <fstream>
#include <iostream>
#include <vector>

std::ofstream score("score.txt");

template <typename T>
inline void assert(const T& condition, const std::string& message) {
    if (!condition) {
        std::cerr << message << std::endl;
        score << -1 << std::endl;
        exit(0);
    }
}

int main() {
    std::ifstream datin("input");
    int n, nguess = 0;
    datin >> n;
    std::vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        datin >> nums[i];
    }

    while (true) {
        std::string cmd;
        std::cin >> cmd;
        if (cmd == "get_num") {
            std::cout << n << std::endl
                      << std::flush;
        } else if (cmd == "guess") {
            nguess++;
            int index, val;
            assert(std::cin >> index >> val, "Invalid `index` or `val` in `guess` command!");
            assert(0 <= index && index < n, "`index` must in [0, n)!");

            if (val < nums[index]) {
                std::cout << -1 << std::endl
                          << std::flush;
            } else if (val > nums[index]) {
                std::cout << 1 << std::endl
                          << std::flush;
            } else {
                std::cout << 0 << std::endl
                          << std::flush;
            }
        } else if (cmd == "submit") {
            bool wrongAnswer = false;
            for (int i = 0; i < n; i++) {
                int x;
                assert(std::cin >> x, "Can't read the " + std::to_string(i) + "-th number!");

                if (x != nums[i] && !wrongAnswer) {
                    wrongAnswer = true;
                    std::cerr << "First differ on the " + std::to_string(i) + "-th number!" << std::endl;
                    score << 0 << std::endl;
                }
            }

            if (!wrongAnswer) {
                score << std::max(std::min(100.0, (950.0 - ((double)nguess / n - 100.0)) / 950.0 * 100.0), 0.0) << std::endl;
                std::cerr << "nguess = " + std::to_string(nguess) << std::endl;
            }

            exit(0);
        } else {
            assert(false, "Invalid command `" + cmd + "`!");
        }
    }
}
