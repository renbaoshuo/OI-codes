#include<bits/stdc++.h>

using namespace std;

int f[1000005];

int find(int x) {
    return f[x] == x ? x : f[x] = find(f[x]);
}

int main() {
    int n, m, z, x, y;
    cin >> n >> m;
    for(int i = 0; i < n ; i++) {
        f[i] = i;
    }
    while(m--) {
        cin >> z >> x >> y;
        if(z == 1) {
            f[find(x)] = find(y);
        }
        else {
            cout << (find(x) == find(y) ? "Y" : "N") << endl;
        }
    }
    return 0;
}
