// R38779683

#include <bits/stdc++.h>

using namespace std;

struct node {
    string name;
    int    chinese;
    int    math;
    int    english;
    int    all;

    node() {
        this->name    = "";
        this->chinese = this->math = this->english = this->all = 0;
    }

    void read() {
        cin >> this->name >> this->chinese >> this->math >> this->english;
        this->all = this->chinese + this->math + this->english;
    }
};

bool cmp(node a, node b) {
    return a.all > b.all;
}

bool query(node a, node b) {
    if(abs(a.chinese - b.chinese) <= 5) {
        if(abs(a.math - b.math) <= 5) {
            if(abs(a.english - b.english) <= 5) {
                if(abs(a.all - b.all) <= 10) {
                    return true;
                }
            }
        }
    }
    return false;
}

int main() {
    int  n;
    node a[1005];
    cin >> n;
    for (int i = 0; i < n; i++) {
        a[i].read();
    }
    // sort(a, a + n, cmp);
    for(int i = 0 ; i < n ; i++) {
        for(int j = i+1 ; j < n ; j++) {
            if(query(a[i], a[j])) {
                if(a[i].name < a[j].name) {
                    cout << a[i].name << ' ' << a[j].name << endl;
                }
                else {
                    cout << a[j].name << ' ' << a[i].name << endl;
                }
            }
        }
    }
    return 0;
}
