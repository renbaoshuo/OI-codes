#include <bits/stdc++.h>

using namespace std;

long long l[150005], lw[150005], lws[150005];
string s;

int main() {
    cin >> s;
    s = ' ' + s;
    for (int i = 1; i < s.size(); i++) {
        l[i] = l[i - 1] + (s[i] == 'L');
        lw[i] = lw[i - 1] + (s[i] == 'W') * l[i];
        lws[i] = lws[i - 1] + (s[i] == 'S') * lw[i];
    }
    cout << lws[s.size() - 1] << endl;
    return 0;
}
