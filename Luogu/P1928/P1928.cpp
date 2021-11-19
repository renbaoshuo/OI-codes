// https://www.luogu.com.cn/record/38657002

#include <bits/stdc++.h>

using namespace std;

string cnm() {
    int n;
    char ch;
    string s = "";
    string str = "";

    while (cin >> ch) {
        if (ch == '[') {
            cin >> n;
            str = cnm();
            while (n--) {
                s += str;
            }
        } else if (ch == ']') {
            return s;
        } else {
            s += ch;
        }
    }

    return s;
}

int main() {
    cout << cnm() << endl;
    return 0;
}
