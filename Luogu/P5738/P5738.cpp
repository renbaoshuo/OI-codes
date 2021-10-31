// R38743182

#include <bits/stdc++.h>

using namespace std;

struct node {
    int    score[22];
    double sum, all;

    node() {
        memset(this->score, 0x00, sizeof(this->score));
        all = sum = 0.00;
    }

    void t(int m) {
        for (int i = 0; i < m; i++) {
            cin >> score[i];
        }
        std::sort(score, score + m);
        for (int i = 1; i + 1 < m; i++) {
            sum += score[i];
        }
        all = sum / (m - 2.00);
    }
};

bool cmp(node a, node b) {
    return a.all > b.all;
}

int main() {
    int  n, m;
    node student[105];
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        student[i].t(m);
    }
    sort(student, student + n, cmp);
    printf("%.2lf", student[0].all);
    return 0;
}
