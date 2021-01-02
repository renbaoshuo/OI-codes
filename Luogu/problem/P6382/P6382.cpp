// R39592154

#include<bits/stdc++.h>

using namespace std;

int main() {
    string name;
    cin >> name;
    if(name[0] != 'M' || name[1] != 'D' || name[2] != 'A') {
        cout << "1 1 1 1 1" << endl;
    } else {
        int i = 7;
        while(!('0' <= name[i] && name[i] <= '9')) i--;
        int last = name[i] - '0';
        cout << (last == 1 || last == 9 ? 1 : 0) << ' ';
        cout << (last == 2 || last == 8 ? 1 : 0) << ' ';
        cout << (last == 3 || last == 7 ? 1 : 0) << ' ';
        cout << (last == 4 || last == 6 ? 1 : 0) << ' ';
        cout << (last == 5 || last == 0 ? 1 : 0) << endl;
    }
    return 0;
}
