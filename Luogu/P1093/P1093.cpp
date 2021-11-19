#include <bits/stdc++.h>

using namespace std;

struct node {
    int chinese, math, english, all, id;

    node() {
        id = chinese = math = english = all = 0;
    }
    node(int _id, int _chinese, int _math, int _english) {
        id = _id;
        chinese = _chinese;
        math = _math;
        english = _english;
        all = chinese + math + english;
    }
};

bool cmp(node a, node b) {
    if (a.all == b.all) {
        if (a.chinese == b.chinese) {
            return a.id < b.id;
        }
        return a.chinese > b.chinese;
    }
    return a.all > b.all;
}

int main() {
    int n;
    node a[305];
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i].chinese >> a[i].math >> a[i].english;
        a[i].all = a[i].chinese + a[i].math + a[i].english;
        a[i].id = i + 1;
    }
    sort(a, a + n, cmp);
    for (int i = 0; i < 5; i++) {
        cout << a[i].id << ' ' << a[i].all << endl;
    }
    return 0;
}