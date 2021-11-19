#include <bits/stdc++.h>

using namespace std;

int ans;
string s;

int main() {
    cin >> s;
    sort(s.begin(), s.end());
    do
        ans++;
    while (next_permutation(s.begin(), s.end()));
    cout << ans << endl;
    return 0;
}
