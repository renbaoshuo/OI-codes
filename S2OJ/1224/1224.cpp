#include <cmath>
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

const int N = 100005;

int n;
long long k, permutation[N];
bool vis[N];

inline long long fact(long long x) {
    long long res = 1;
    while (x) {
        res *= x--;
    }
    return res;
}

void revContor(int n, long long k) {
    k--;
    for (int i = 1; i <= n; i++) {
        long long cnt = k / fact(n - i);
        for (int j = 1; j <= n; j++) {
            if (!vis[j]) {
                if (!cnt) {
                    permutation[i] = j;
                    vis[j] = true;
                    break;
                }
                cnt--;
            }
        }
        k %= fact(n - i);
    }
}

int main() {
    cin >> n >> k;
    revContor(n, k);
    for (int i = 1; i <= n; i++) {
        cout << permutation[i] << ' ';
    }
    cout << endl;
    return 0;
}
