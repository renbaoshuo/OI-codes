#include <bits/stdc++.h>

using namespace std;

int main() {
    int              n, q, a, b;
    string           s;
    map<string, int> students;
    cin >> n;
    while (n--) {
        cin >> q;
        if (q == 1) {
            cin >> s >> b;
            students[s] = b;
            cout << "OK" << endl;
        }
        else if (q == 2) {
            cin >> s;
            if (students.find(s) != students.end()) {
                cout << students[s] << endl;
            }
            else {
                cout << "Not found" << endl;
            }
        }
        else if (q == 3) {
            cin >> s;
            if (students.find(s) != students.end()) {
                students.erase(s);
                cout << "Deleted successfully" << endl;
            }
            else {
                cout << "Not found" << endl;
            }
        }
        else if(q == 4) {
            cout << students.size() << endl;
        }
    }
    return 0;
}
