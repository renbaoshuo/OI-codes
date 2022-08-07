#include <iostream>
#include <algorithm>
#include <string>

using std::cin;
using std::cout;
const char endl = '\n';

int t, n, a, e;
std::string s;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;

    while (t--) {
        cin >> n >> a >> e >> s;

        int cnt = std::count(s.begin(), s.end(), 'A');

        if (a > cnt) {
            if (a - cnt > e || (e - (a - cnt)) % 2) {
                cout << -1 << endl;
            } else {
                int cnt1 = e - (a - cnt) >> 1,
                    cnt2 = (a - cnt) + (e - (a - cnt) >> 1);

                for (char c : s) {
                    if (c == 'A') {
                        if (cnt1 > 0) {
                            cout << 'B';
                            cnt1--;
                        } else {
                            cout << 'A';
                        }
                    } else {  // c == 'B'
                        if (cnt2 > 0) {
                            cout << 'A';
                            cnt2--;
                        } else {
                            cout << 'B';
                        }
                    }
                }

                cout << endl;
            }
        } else if (a == cnt) {
            if (e & 1) {
                cout << -1 << endl;
            } else {
                int cnt1 = e >> 1,
                    cnt2 = e >> 1;

                for (char c : s) {
                    if (c == 'A') {
                        if (cnt1 > 0) {
                            cout << 'B';
                            cnt1--;
                        } else {
                            cout << 'A';
                        }
                    } else {  // c == 'B'
                        if (cnt2 > 0) {
                            cout << 'A';
                            cnt2--;
                        } else {
                            cout << 'B';
                        }
                    }
                }

                cout << endl;
            }
        } else {  // a < cnt
            if (cnt - a > e || (e - (cnt - a)) % 2) {
                cout << -1 << endl;
            } else {
                int cnt1 = (cnt - a) + (e - (cnt - a) >> 1),
                    cnt2 = e - (cnt - a) >> 1;

                for (char c : s) {
                    if (c == 'A') {
                        if (cnt1 > 0) {
                            cout << 'B';
                            cnt1--;
                        } else {
                            cout << 'A';
                        }
                    } else {  // c == 'B'
                        if (cnt2 > 0) {
                            cout << 'A';
                            cnt2--;
                        } else {
                            cout << 'B';
                        }
                    }
                }

                cout << endl;
            }
        }
    }

    return 0;
}
