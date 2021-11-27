#include <bits/stdc++.h>
using namespace std;

namespace erwqergdczxv {
    static int n, m, cnt;
    static bool hasUsedGetN = false;
    static bool hasSubmitted = false;

    void RE() {
        puts("re");
        exit(0);
    }

    int getn() {
        if (hasUsedGetN) RE();
        cin >> n;
        hasUsedGetN = 1;
        m = rand() % n + 1;
        return n;
    }

    int query(int x) {
        if (!hasUsedGetN || hasSubmitted) RE();
        cnt++;
        if (cnt > 100000) RE();
        if (x == m)
            return (rand() % 10 <= 3);
        else
            return (rand() % 10 <= 4);
    }

    void submit(int x) {
        if (hasSubmitted) RE();
        if (x == m)
            puts("ok");
        else
            puts("wa");
        hasSubmitted = 1;
    }
}  // namespace erwqergdczxv

using erwqergdczxv::getn;
using erwqergdczxv::query;
using erwqergdczxv::submit;
