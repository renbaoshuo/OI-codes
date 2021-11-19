// R38990825

#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b, c;
    string ans;
    cin >> a >> b;
    c = max(a, b);
    switch (c) {
        case 1:
            ans = "1/1";
            break;
        case 2:
            ans = "5/6";
            break;
        case 3:
            ans = "2/3";
            break;
        case 4:
            ans = "1/2";
            break;
        case 5:
            ans = "1/3";
            break;
        case 6:
            ans = "1/6";
            break;
    }
    cout << ans << endl;
    return 0;
}
