// R38710051

#include <bits/stdc++.h>

using namespace std;

struct node {
    string name;
    int chinese;
    int math;
    int english;
    int all;

    node() {
        name = "";
        chinese = math = english = all = 0;
    }

    void read() {
        cin >> this->name >> this->chinese >> this->math >> this->english;
        this->all = this->chinese + this->math + this->english;
    }
};

bool cmp(node a, node b) {
    return a.all > b.all;
}

int main() {
    int n;
    node a[1005];
    cin >> n;
    for (int i = 0; i < n; i++) {
        a[i].read();
    }
    sort(a, a + n, cmp);
    cout << a[0].name << ' ' << a[0].chinese << ' ' << a[0].math << ' ' << a[0].english << endl;
    return 0;
}
