#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            cout << ' ';
        }
        cout << '+';
        for (int j = 1; j < 2 * n - 2 * i; j++) {
            cout << ' ';
        }
        cout << '+' << endl;
    }
    for (int i = 0; i < n; i++) {
        cout << ' ';
    }
    cout << '+' << endl;
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < i; j++) {
            cout << ' ';
        }
        cout << '+';
        for (int j = 1; j < 2 * n - 2 * i; j++) {
            cout << ' ';
        }
        cout << '+' << endl;
    }
    cout << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            cout << ' ';
        }
        cout << '+';
        for (int j = 1; j < 2 * n - 2 * i; j++) {
            cout << ' ';
        }
        cout << '+' << endl;
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < n; j++) {
            cout << ' ';
        }
        cout << '+' << endl;
    }
    cout << endl;
    for (int i = 0; i < n * 2; i++) {
        cout << '+';
    }
    cout << endl;
    for (int i = 1; i < n * 2; i++) {
        cout << '+';
        for (int i = 1; i < n * 2; i++) {
            cout << ' ';
        }
        cout << '+' << endl;
    }
    for (int i = 0; i < n * 2; i++) {
        cout << '+';
    }
    cout << endl;
    return 0;
}
