#include <bits/stdc++.h>

using namespace std;

bool check(string s) {
    string r = s;
    reverse(r.begin(), r.end());
    return r == s;
}

string add(string b, int k) {
    string a        = b;
    char   sixt[20] = "0123456789ABCDEF";
    reverse(a.begin(), a.end());
    int    numa[105], numb[105], numc[105];
    int    len = a.length(), lenc = 1;
    string ans;
    for (int i = 0; i < len; i++) {
        if (isdigit(a[i])) {
            numa[len - i] = a[i] - '0';
        }
        else {
            numa[len - i] = a[i] - 'A' + 10;
        }
        if (isdigit(b[i])) {
            numb[len - i] = b[i] - '0';
        }
        else {
            numb[len - i] = b[i] - 'A' + 10;
        }
    }
    int x = 0;
    while (lenc <= len) {
        numc[lenc] = numa[lenc] + numb[lenc] + x;
        x          = numc[lenc] / k;
        numc[lenc] %= k;
        lenc++;
    }
    numc[lenc] = x;
    while (numc[lenc] == 0) {
        lenc--;
    }
    for (int i = lenc; i >= 1; i--) {
        ans += sixt[numc[i]];
    }
    return ans;
}

int main() {
    int    n;
    string m;
    cin >> n >> m;
    for (int i = 0; i <= 30; i++) {
        if (check(m)) {
            cout << "STEP=" << i << endl;
            return 0;
        }
        m = add(m, n);
    }
    cout << "Impossible!" << endl;
    return 0;
}
