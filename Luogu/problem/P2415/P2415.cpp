// R38780934

#include <bits/stdc++.h>

using namespace std;

int main() {
    long long sum, a, i;
    sum = a = i = 0;
    while (cin >> a) {
        sum += a;
        i++;
    }
    sum *= 2 << i - 2;
    cout << sum << endl;
    return 0;
}
