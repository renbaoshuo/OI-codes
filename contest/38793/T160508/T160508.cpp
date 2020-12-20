#include <bits/stdc++.h>

using namespace std;

int main() {
    int score;
    double gpa = 0.0;
    cin >> score;
    if (score >= 90) {
        gpa = 4.0;
    }
    else if (60 <= score && score <= 89) {
        gpa = 4.0 - (90 - score) * 0.1;
    }
    else {
        if (floor(sqrt(score) * 10.0) >= 90.0) {
            gpa = 4.0;
        }
        else if (floor(sqrt(score) * 10.0) >= 60.0) {
            gpa = 4.0 - (90.0 - floor(sqrt(score) * 10.0)) * 0.1;
        }
        else {
            gpa = 0.0;
        }
    }
    cout << fixed << setprecision(1) << gpa << endl;
    return 0;
}
