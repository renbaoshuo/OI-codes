#include<bits/stdc++.h>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.first == b.first ? a.second < b.second : a.first < b.first;
}

int main() {
    int n;
    pair<int, int> p[200005];
    cin >> n;
    for(int i = 0 ; i < n ; i++) {
        cin >> p[i].first >> p[i].second;
    }
    sort(p, p+n, cmp);
    int tv1 = -1, tv2 = -1;
    for(int i = 0 ; i  < n ; i++) {
        if(p[i].first > tv1) {
            tv1 = p[i].second;
        }
        else {
            if(p[i].first > tv2) {
                tv2 = p[i].second;
            }
            else {
                cout << "NO" << endl;
                return 0;
            }
        }
    }
    cout << "YES" << endl;
    return 0;
}
