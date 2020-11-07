#include<bits/stdc++.h>

using namespace std;

int main() {
    int n, a[100005], k;
    priority_queue<int, vector<int>, less<int> > s;
    priority_queue<int, vector<int>, greater<int> > l;
    cin >> n;
    for(int i = 1 ; i <= n ; i++) {
        cin >> a[i];
        k = i/2+1;
        if(!l.empty() && a[i] >= l.top()) {
            s.push(a[i]);
        }
        else {
            l.push(a[i]);
        }
        while(l.size() < k) {
            l.push(s.top());
            s.pop();
        }
        while(s.size() < k) {
            s.push(l.top());
            l.pop();
        }
        if(i%2) {
            cout << s.top() << endl;
        }
    }
    return 0;
}
