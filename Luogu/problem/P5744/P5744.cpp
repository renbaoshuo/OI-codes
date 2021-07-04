// R38782109

#include <bits/stdc++.h>

using namespace std;

int main() {
    int    n;
    string name;
    int    age;
    int    score;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> name >> age >> score;
        cout << name << ' ' << ++age << ' ' << ((int)(score * 1.2) > 600 ? 600 : (int)(score * 1.2)) << endl;
    }
    return 0;
}
