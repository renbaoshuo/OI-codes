#include <bits/stdc++.h>

using namespace std;

int n;
string op, ad;
map<string, long long> server;

bool check(string s) {
    long long cnt1 = 0, cnt2 = 0, now = 0, flag = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '.') {
            cnt1++;
            if (cnt2) return 0;
            if (i == 0 || s[i - 1] == '.') return false;
            if (cnt1 > 3) return false;
            if (now < 0 || now > 255) return false;
            flag = 0;
            now = 0;
            continue;
        }
        if (s[i] == ':') {
            cnt2++;
            if (i == s.size() - 1) return false;
            if (cnt2 > 1) return false;
            if (i == 0 || s[i - 1] == ':') return false;
            if (now < 0 || now > 255) return false;
            flag = 0;
            now = 0;
            continue;
        }
        if (s[i] < '0' || s[i] > '9') return false;
        if (s[i] == '0' && flag == 0) flag = 1;
        if (s[i] != '0' && flag == 1) return 0;
        if (s[i] != '0') flag = 2;
        now = now * 10 + s[i] - '0';
    }
    if (cnt1 != 3 || cnt2 != 1) return false;
    if (now < 0 || now > 65535) return false;
    return true;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> op >> ad;
        if (check(ad)) {
            if (op == "Server") {
                if (server.count(ad)) {
                    cout << "FAIL" << endl;
                } else {
                    server[ad] = i;
                    cout << "OK" << endl;
                }
            } else {
                if (server.count(ad)) {
                    cout << server[ad] << endl;
                } else {
                    cout << "FAIL" << endl;
                }
            }
        } else {
            cout << "ERR" << endl;
        }
    }
    return 0;
}
