#include <bits/stdc++.h>

#include "interaction.h"

using namespace std;

int n;
vector<int> ans;

int main() {
    n = get_num();
    for (int i = 0; i < n; i++) {
        int l = 0, r = 1000000;

        while (l <= r) {
            int mid = (l + r) >> 1, feedback = guess(i, mid);

            if (!feedback) {
                ans.emplace_back(mid);
                break;
            } else {
                if (feedback > 0) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
        }
    }
    submit(ans);
    return 0;
}