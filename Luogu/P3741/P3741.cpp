// R38667882

#include <bits/stdc++.h>

using namespace std;

int count(string str) {
    int sum = 0;
    for (int i = 0; i < str.size() - 1; i++)
        if (str[i] == 'V' && str[i + 1] == 'K')
            sum++;
    return sum;
}

int main() {
    int n, max;
    string str;

    cin >> n >> str;

    max = count(str);

    for (int i = 0; i < str.size(); i++) {
        if (str[i] == 'V') {
            str[i] = 'K';
        } else {
            str[i] = 'V';
        }

        int s = count(str);

        if (s > max) {
            max = s;
        }
        if (str[i] == 'V') {
            str[i] = 'K';
        } else {
            str[i] = 'V';
        }
    }

    cout << max << endl;

    return 0;
}
