#include <bits/stdc++.h>

using namespace std;

long long n, m, ans;
string s[10005], r[10005], tmp;

int main() {
    while (getline(cin, tmp), tmp != "EOF") {
        n++;
        for (long long i = 0; i < tmp.size(); i++) {
            if (tmp[i] == '<') {
                if (!s[n].empty()) s[n].pop_back();
            } else {
                s[n].push_back(tmp[i]);
            }
        }
    }
    while (getline(cin, tmp), tmp != "EOF") {
        if (++m > n) continue;
        for (long long i = 0; i < tmp.size(); i++) {
            if (tmp[i] == '<') {
                if (!r[m].empty()) r[m].pop_back();
            } else {
                r[m].push_back(tmp[i]);
            }
        }
        for (long long i = 0; i < min(r[m].size(), s[m].size()); i++) {
            if (r[m][i] == s[m][i]) ans++;
        }
    }
    cin >> m;
    cout << (int)(ans * 60.0 / m + 0.5) << endl;
    return 0;
}
