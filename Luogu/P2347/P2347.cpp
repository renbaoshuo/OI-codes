#include <bits/stdc++.h>

using namespace std;

int w[10], ans;
bool cnt[1005];

int main() {
    for (int i = 1; i <= 6; i++) {
        cin >> w[i];
    }
    for (int a = 0; a <= w[1]; a++) {
        for (int b = 0; b <= w[2]; b++) {
            for (int c = 0; c <= w[3]; c++) {
                for (int d = 0; d <= w[4]; d++) {
                    for (int e = 0; e <= w[5]; e++) {
                        for (int f = 0; f <= w[6]; f++) {
                            cnt[a + b * 2 + c * 3 + d * 5 + e * 10 + f * 20] = true;
                        }
                    }
                }
            }
        }
    }
    for (int i = 1; i <= 1000; i++) {
        ans += cnt[i];
    }
    cout << "Total=" << ans << endl;
    return 0;
}
