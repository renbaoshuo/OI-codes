// R38953830

#include <bits/stdc++.h>

using namespace std;

int main() {
    char c;
    int  a[30] = {0};
    while (cin >> c) {
        a[c - 'a']++;
    }
    sort(a, a + 26);
    cout << a[25] << endl;
    return 0;
}
