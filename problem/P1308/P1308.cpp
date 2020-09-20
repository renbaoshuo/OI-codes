// https://www.luogu.com.cn/record/38659937

#include <bits/stdc++.h>

using namespace std;

int main() {
    int    cnt = 0, t = 0;
    string word, p;

    getline(cin, word);
    getline(cin, p);

    for (int i = 0; i < word.size(); i++) {
        if ('a' <= word[i] && word[i] <= 'z') {
            word[i] -= 32;
        }
    }
    for (int i = 0; i < p.size(); i++) {
        if ('a' <= p[i] && p[i] <= 'z') {
            p[i] -= 32;
        }
    }

    word = ' ' + word + ' ';
    p    = ' ' + p + ' ';

    if (p.find(word) == string::npos) {
        cout << -1 << endl;
        return 0;
    }

    while (t != string::npos) {
        cnt++;
        t = p.find(word, t + 1);
    }

    cout << --cnt << ' ' << p.find(word) << endl;

    return 0;
}