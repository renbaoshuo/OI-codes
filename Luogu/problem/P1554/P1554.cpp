// https://www.luogu.com.cn/record/36226094

#include <bits/stdc++.h>

using namespace std;

int n, m, js[10];

int main() {
	cin >> n >> m;
	for(int i = n ; i <= m ; i++) {
        for(int j = i ; j ; j /= 10) {
            js[j%10]++;
        }
    } 
	for(int i = 0 ; i < 10 ; i++) {
        cout << js[i] << " ";
    }
    return 0;
}
