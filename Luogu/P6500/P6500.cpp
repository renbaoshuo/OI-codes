// R39634200

#include <bits/stdc++.h>

using namespace std;

int main() {
    string a, b, a_max, b_max, a_min, b_min;
    cin >> a >> b;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == '6' || a[i] == '5')
            a_max += '6', a_min += '5';
        else
            a_max += a[i], a_min += a[i];
    }
    for (int i = 0; i < b.size(); i++) {
        if (b[i] == '6' || b[i] == '5')
            b_max += '6', b_min += '5';
        else
            b_max += b[i], b_min += b[i];
    }
    cout << atoi(a_min.c_str()) + atoi(b_min.c_str()) << ' ' << atoi(a_max.c_str()) + atoi(b_max.c_str()) << endl;
    return 0;
}
