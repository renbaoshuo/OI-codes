// https://www.luogu.com.cn/record/38654562

#include<bits/stdc++.h>

using namespace std;

int main() {
    int a, b, c;
    string s;

    a = b = c = 0;
    cin >> s;

    for(int i = 0 ; i < s.size() ; i += 5) {
        cout << s[i] << ' ' << s[i+3] << ' ';
        switch(s[i]) {
            case 'a':
                if('0' <= s[i+3] && s[i+3] <= '9') {
                    a = s[i+3] - '0';
                } else {
                    switch(s[i+3]) {
                        case 'a':
                            a = a;
                            break;
                        case 'b':
                            a = b;
                            break;
                        case 'c':
                            a = c;
                            break;
                    }
                }
                break;
            case 'b':
                if('0' <= s[i+3] && s[i+3] <= '9') {
                    b = s[i+3] - '0';
                } else {
                    switch(s[i+3]) {
                        case 'a':
                            b = a;
                            break;
                        case 'b':
                            b = b;
                            break;
                        case 'c':
                            b = c;
                            break;
                    }
                }
                break;
            case 'c':
                if('0' <= s[i+3] && s[i+3] <= '9') {
                    c = s[i+3] - '0';
                } else {
                    switch(s[i+3]) {
                        case 'a':
                            c = a;
                            break;
                        case 'b':
                            c = b;
                            break;
                        case 'c':
                            c = c;
                            break;
                    }
                }
                break;
        }
        cout << a << ' ' << b << ' ' << c << endl;
    }
    printf("%d %d %d\n", a, b, c);

    return 0;
}
