#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    map<char, int> m;
    queue<char> q;
    cin >> s;
    for (char i : s) {
        m[i]++;
        q.push(i);
    }
    while (!q.empty()) {
        if (m[q.front()] == 1) {
            cout << q.front() << endl;
            exit(0);
        }
        q.pop();
    }
    cout << "no" << endl;
    return 0;
}
