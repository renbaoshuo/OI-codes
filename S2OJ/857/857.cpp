#include <bits/stdc++.h>

using namespace std;

int n, a, l, r;
string s, s1, s2;

int main() {
    getline(cin, s, ',');
    getline(cin, s1, ',');
    getline(cin, s2);
    n = s.find(s1);
    a = s.rfind(s2);
    l = s1.size();
    r = s2.size();
    cout << (a <= n || a == -1 || n == -1 || a < n + l - 1 ? -1 : a - n - l) << endl;
}
