#include <bits/stdc++.h>

using namespace std;

double x;

int main() {
    cin >> x;
    if (0 <= x && x <= 25) {
        cout << "Intervalo [0,25]" << endl;
    } else if (25 < x && x <= 50) {
        cout << "Intervalo (25,50]" << endl;
    } else if (50 < x && x <= 75) {
        cout << "Intervalo (50,75]" << endl;
    } else if (75 < x && x <= 100) {
        cout << "Intervalo (75,100]" << endl;
    } else {
        cout << "Fora de intervalo" << endl;
    }
    return 0;
}
