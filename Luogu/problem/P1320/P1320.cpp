// R36448319

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, c;   // n: 题意中的N, c: count
    char l;     // 上一个出现的字符
    string s[205]; // 数组

    n = c = 0;
    l = '0';

    cin >> s[0];
    n = s[0].size();
    for(int i = 1 ; i < n ; i++) {
        cin >> s[i];
    }

    cout << n << " ";

    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < n ; j++) {
            if(s[i][j] == l) {
                c++;
            } else {
                cout << c << " ";             // 输出以前统计完的
                c = 1;                        // 坑点: 这里一定要赋值为1, 因为当前字符也算
                l = s[i][j];                  // 设置当前字符为继续统计对象
            }
        }
    }
    cout << c << endl;                        // 坑点: 要输出最后一个统计

    return 0;
}
