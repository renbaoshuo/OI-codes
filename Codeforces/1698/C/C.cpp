#include <iostream>
#include <algorithm>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 2e5 + 5;

int t, n, a[N];

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;

    while (t--) {
        bool flag = true;
        std::vector<long long> nums;
        int cnt1 = 0, cnt2 = 0, cnt3 = 0;

        cin >> n;

        for (int i = 1, x; i <= n; i++) {
            cin >> a[i];

            if (a[i] < 0) cnt1++;
            else if (a[i] > 0) cnt2++;
            else cnt3++;
        }

        if (cnt1 > 2 || cnt2 > 2) {
            cout << "No" << endl;

            continue;
        }

        cnt3 = std::min(cnt3, 2);

        for (int i = 1; i <= n; i++) {
            if (a[i]) {
                nums.push_back(a[i]);
            }
        }

        for (int i = 1; i <= cnt3; i++) {
            nums.push_back(0);
        }

        int q = nums.size();
        for (int i = 0; i < q; i++) {
            for (int j = i + 1; j < q; j++) {
                for (int k = j + 1; k < q; k++) {
                    long long x = nums[i] + nums[j] + nums[k];
                    bool f = false;
                    for (int l = 0; l < q; l++) {
                        if (x == nums[l]) {
                            f = true;
                            break;
                        }
                    }
                    if (!f) flag = false;
                }
            }
        }

        cout << (flag ? "Yes" : "No") << endl;
    }

    return 0;
}
