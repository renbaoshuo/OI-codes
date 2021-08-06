#include <bits/stdc++.h>

using namespace std;

int main() {
    char op;
    cin >> op;

    double x, sum = 0;
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            cin >> x;
            if (i > j && i + j < 11) sum += x;
        }
    }

    if (op == 'S')
        printf("%.1lf", sum);
    else
        printf("%.1lf", sum / 30);

    return 0;
}
