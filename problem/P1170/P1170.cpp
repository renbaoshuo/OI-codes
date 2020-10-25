#include<bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
    if(b == 0) {
        return a;
    }
    return gcd(b, a%b);
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int ax, ay, bx, by;
        cin >> ax >> ay >> bx >> by;
        cout << (gcd(abs(ax-bx), abs(ay-by)) == 1 ? "no" : "yes") << endl;
    }
    return 0;
}
