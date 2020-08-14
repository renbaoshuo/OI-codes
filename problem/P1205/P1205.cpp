// R36572888

#include<bits/stdc++.h>

using namespace std;

struct Matrix {
    int map[12][12];
    int n;
} from, to;

bool transform1(const Matrix& in) {  // Right 90
    for (int i = 1; i <= in.n; i++) {
        for (int j = 1; j <= in.n; j++) {
            if (in.map[i][j] != to.map[j][in.n - i + 1]) {
                return 0;
            }
        }
    }
    return 1;
}

bool transform2(const Matrix& in) {  // Right 180
    for (int i = 1; i <= in.n; i++) {
        for (int j = 1; j <= in.n; j++) {
            if (in.map[i][j] != to.map[in.n - i + 1][in.n - j + 1]) {
                return 0;
            }
        }
    }
    return 1;
}

bool transform3(const Matrix& in) {  // Right 270
    for (int i = 1; i <= in.n; i++) {
        for (int j = 1; j <= in.n; j++) {
            if (in.map[i][j] != to.map[in.n - j + 1][i])
                return 0;
        }
    }
    return 1;
}

bool transform4(const Matrix& in) {  // Reflect
    for (int i = 1; i <= in.n; i++) {
        for (int j = 1; j <= in.n; j++) {
            if (in.map[i][j] != to.map[i][in.n - j + 1])
                return 0;
        }
    }
    return 1;
}

bool transform5(const Matrix& in) {
    Matrix tmp;
    tmp.n = in.n;
    for (int i = 1; i <= in.n; i++) {
        for (int j = 1; j <= in.n; j++) {
            tmp.map[i][j] = in.map[i][in.n - j + 1];
        }
    }
    return (transform1(tmp) || transform2(tmp) || transform3(tmp));
}

bool transform6(const Matrix& in) {
    for (int i = 1; i <= in.n; i++) {
        for (int j = 1; j < in.n; j++) {
            if (in.map[i][j] != to.map[i][j])
                return 0;
        }
    }
    return 1;
}

int main() {
    scanf("%d", &from.n);
    to.n = from.n;
    string tmp;
    getline(cin, tmp);
    for (int i = 1; i <= from.n; i++) {
        getline(cin, tmp);
        for (int j = 0; j < from.n; j++)
            from.map[i][j + 1] = tmp[j];
    }
    for (int i = 1; i <= to.n; i++) {
        getline(cin, tmp);
        for (int j = 0; j < to.n; j++)
            to.map[i][j + 1] = tmp[j];
    }
    if (transform1(from) == 1) {
        printf("1");
        exit(0);
    }
    if (transform2(from) == 1) {
        printf("2");
        exit(0);
    }
    if (transform3(from) == 1) {
        printf("3");
        exit(0);
    }
    if (transform4(from) == 1) {
        printf("4");
        exit(0);
    }
    if (transform5(from) == 1) {
        printf("5");
        exit(0);
    }
    if (transform6(from) == 1) {
        printf("6");
        exit(0);
    }
    printf("7");
    return 0;
}