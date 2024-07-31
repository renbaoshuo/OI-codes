#include <iostream>
#include <algorithm>
#include <iterator>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e6 + 5;

int n;
int lch[N], rch[N];
int cnt_pre, pre[N],
    cnt_in, in[N],
    cnt_post, post[N];

void pre_order(int u) {
    pre[++cnt_pre] = u;

    if (lch[u]) pre_order(lch[u]);
    if (rch[u]) pre_order(rch[u]);
}

void in_order(int u) {
    if (lch[u]) in_order(lch[u]);

    in[++cnt_in] = u;

    if (rch[u]) in_order(rch[u]);
}

void post_order(int u) {
    if (lch[u]) post_order(lch[u]);
    if (rch[u]) post_order(rch[u]);

    post[++cnt_post] = u;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> lch[i] >> rch[i];
    }

    pre_order(1);
    in_order(1);
    post_order(1);

    std::copy_n(pre + 1, n, std::ostream_iterator<int>(cout, " "));
    cout << endl;
    std::copy_n(in + 1, n, std::ostream_iterator<int>(cout, " "));
    cout << endl;
    std::copy_n(post + 1, n, std::ostream_iterator<int>(cout, " "));
    cout << endl;

    return 0;
}
