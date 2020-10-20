#include <bits/stdc++.h>

using namespace std;

int main() {
    map<string, int> m;
    string           s;
    long long        ans = 0, now = 0;

    m["one"]       = 1;
    m["two"]       = 2;
    m["three"]     = 3;
    m["four"]      = 4;
    m["five"]      = 5;
    m["six"]       = 6;
    m["seven"]     = 7;
    m["eight"]     = 8;
    m["nine"]      = 9;
    m["ten"]       = 10;
    m["eleven"]    = 11;
    m["twelve"]    = 12;
    m["thirteen"]  = 13;
    m["fourteen"]  = 14;
    m["fifteen"]   = 15;
    m["sixteen"]   = 16;
    m["seventeen"] = 17;
    m["eighteen"]  = 18;
    m["nineteen"]  = 19;
    m["twenty"]    = 20;
    m["thirty"]    = 30;
    m["forty"]     = 40;
    m["fifty"]     = 50;
    m["sixty"]     = 60;
    m["seventy"]   = 70;
    m["eighty"]    = 80;
    m["ninety"]    = 90;

    while (cin >> s) {
        if (s == "negative") {
            cout << "-";
        }
        else if (s == "hundred") {
            ans += now;
            ans *= 100;
            now = 0;
        }
        else if (s == "thousand") {
            ans += now;
            ans *= 1000;
            now = 0;
        }
        else if (s == "million") {
            ans += now;
            ans *= 1000000;
            now = 0;
        }
        else {
            now += m[s];
        }
    }
    if (now) {
        ans += now;
    }
    cout << ans << endl;
    return 0;
}
