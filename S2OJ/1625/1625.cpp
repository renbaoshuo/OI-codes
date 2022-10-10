#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

std::string s, t;
int cnt[10];

void add(int x, int f = 1) {
    switch (x) {
        case 4:
            cnt[3] += f;
            cnt[2] += 2 * f;

            break;

        case 6:
            cnt[5] += f;
            cnt[3] += f;

            break;

        case 8:
            cnt[7] += f;
            cnt[2] += 3 * f;

            break;

        case 9:
            cnt[7] += f;
            cnt[3] += 2 * f;
            cnt[2] += f;

            break;

        default:
            cnt[x] += f;

            break;
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> s;

    for (char c : s) {
        add(c - '0');
    }

    while (cnt[7] >= 1 && cnt[3] >= 2 && cnt[2] >= 1) {
        add(9, -1);

        t.push_back('9');
    }

    while (cnt[7] >= 1 && cnt[2] >= 3) {
        add(8, -1);
        t.push_back('8');
    }

    while (cnt[7]) {
        add(7, -1);
        t.push_back('7');
    }

    while (cnt[5] && cnt[3]) {
        add(6, -1);
        t.push_back('6');
    }

    while (cnt[5]) {
        add(5, -1);
        t.push_back('5');
    }

    while (cnt[3] >= 1 && cnt[2] >= 2) {
        add(4, -1);
        t.push_back('4');
    }

    while (cnt[3]) {
        add(3, -1);
        t.push_back('3');
    }

    while (cnt[2]) {
        add(2, -1);
        t.push_back('2');
    }

    cout << (t.empty() ? "?????" : t) << endl;

    return 0;
}
