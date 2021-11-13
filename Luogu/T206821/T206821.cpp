#include <bits/stdc++.h>

using namespace std;

int n, k, s;
vector<int> a, b;

int main() {
    cin >> n >> k;
    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            a.push_back(i);
            n /= i;
        }
    }
    if (n > 1) a.push_back(n);
    for (int i : a) {
        s += i;
        b.push_back(i);
    }
    if (s > k) {
        cout << -1 << endl;
        exit(0);
    }
    while (s < k) {
        b.push_back(1);
        s++;
    }
    cout << b.size() << endl;
    for (int i : b) {
        cout << i << ' ';
    }
    cout << endl;
    return 0;
}
