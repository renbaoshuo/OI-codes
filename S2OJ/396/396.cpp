// ios::sync_with_stdio(0);
// cin.tie(nullptr);cout.tie(nullptr);
// int n,m,ans=0;cin>>m>>n;
// for (int i=1;i<=n;i++) fa[i]=i;
// for (int i=1;i<=m;i++){
// 	int x;cin>>x;int pos=find(x);
// 	merge(pos,pos-1);(ans+=pos*i)%=mod;
// }cout<<ans;return 0;

#include <iostream>
#include <numeric>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 3000000;
const int mod = 1e9 + 7;

int n, m, fa[N], ans;

int find(int x) {
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}

void merge(int x, int y) {
    fa[find(x)] = find(y);
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    std::iota(fa + 1, fa + m + 1, 1);

    for (int i = 1, x; i <= n; i++) {
        cin >> x;

        int p = find(x);

        merge(p, p - 1);

        ans = (ans + static_cast<long long>(p) * i) % mod;
    }

    cout << ans << endl;

    return 0;
}
