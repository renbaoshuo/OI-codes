#include <bits/stdc++.h>

using namespace std;

int n, x, maxx = -1;
long long mind = 0x3f3f3f3f3f3f3f3f;

struct node {
    int x;
    long long d;
} s[100005];

pair<long long, int> a[100005];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        a[i].first = a[i - 1].first + x;
        a[i].second = i;
    }
    sort(a, a + 1 + n);
    for (int i = 2; i <= n; i++) {
        if (a[i].first - a[i - 1].first < mind || a[i].first - a[i - 1].first == mind && abs(a[i].second - a[i - 1].second) > maxx) {
            mind = a[i].first - a[i - 1].first;
            maxx = abs(a[i].second - a[i - 1].second);
        }
    }
    cout << mind << endl
         << maxx << endl;
    return 0;
}
