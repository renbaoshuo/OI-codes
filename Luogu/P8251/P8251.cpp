#include <iostream>
#include <stack>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 5e5 + 5;

struct node {
    int a, b, idx;

    node()
        : a(0),
          b(0),
          idx(0) {}

    node(int _a, int _b, int _idx)
        : a(_a),
          b(_b),
          idx(_idx) {}
};

int n, q, a[N], b[N], id[N], t[N], ans[N];
std::stack<node> st;
std::vector<int> aa[N], bb[N];
std::pair<int, int> qq[N];

int lowbit(int x) {
    return x & (-x);
}

void add(int x) {
    for (; x <= n; x += lowbit(x))
        t[x]++;
}

int ask(int x) {
    int ans = 0;
    for (; x; x -= lowbit(x))
        ans += t[x];
    return ans;
}

inline int sum(int x, int y) {
    return ask(y) - ask(x - 1);
}

int main() {
    std::ios::sync_with_stdio(false);

    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }

    st.push(node(-1, 0, 0));
    for (int i = 1; i <= n; i++) {
        while (!st.empty() && (st.top().a == a[i] || st.top().b <= b[i])) st.pop();
        if (!st.empty()) id[i] = st.top().idx;
        st.push(node(a[i], b[i], i));
    }

    for (int i = 1; i <= n; i++) {
        aa[id[i]].push_back(i);
    }
    for (int i = 1; i <= q; i++) {
        cin >> qq[i].first >> qq[i].second;
        bb[qq[i].first].push_back(i);
    }

    for (int i = 1; i <= n; i++) {
        for (int k = 0; k < aa[i - 1].size(); k++) {
            add(aa[i - 1][k]);
        }
        for (int t : bb[i]) {
            int l = qq[t].first,
                r = qq[t].second;
            ans[t] = sum(l, r);
        }
    }

    for (int i = 1; i <= q; i++) {
        cout << ans[i] << endl;
    }

    return 0;
}
