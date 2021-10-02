#include <bits/stdc++.h>

using namespace std;

int n, s1, s2, sum = 0, maxq = 0, tot = 0, x, i;
char a, b;
string name, maxn;

int main() {
    cin >> n;
    for (i = 1; i <= n; i++) {
        cin >> name >> s1 >> s2 >> a >> b >> x;
        if (s1 > 80 && x > 0) {
            sum += 8000;
        }
        if (s1 > 85 && s2 > 80) {
            sum += 4000;
        }
        if (s1 > 90) {
            sum += 2000;
        }
        if (s1 > 85 && b == 'Y') {
            sum += 1000;
        }
        if (s2 > 80 && a == 'Y') {
            sum += 850;
        }
        tot += sum;
        if (sum > maxq) {
            maxn = name;
            maxq = sum;
        }
        sum = 0;
    }
    cout << maxn << endl
         << maxq << endl
         << tot << endl;
    return 0;
}
