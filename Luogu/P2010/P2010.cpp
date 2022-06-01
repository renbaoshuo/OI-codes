#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>

const int days[] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

struct node {
    int year, month, day;
} date1, date2;

using namespace std;

int ans;
std::string s1, s2;

int main() {
    scanf("%4d%2d%2d", &date1.year, &date1.month, &date1.day);
    scanf("%4d%2d%2d", &date2.year, &date2.month, &date2.day);
    for (int yy = date1.year; yy <= date2.year; yy++) {
        for (int mm = (yy == date1.year ? date1.month : 1);
             mm <= (yy == date2.year ? date2.month : 12);
             mm++) {
            for (int dd = (yy == date1.year && mm == date1.month ? date1.day : 1);
                 dd <= (yy == date2.year && mm == date2.month ? date2.day : days[mm]);
                 dd++) {
                s1 = s2 = std::to_string(yy * 10000 + mm * 100 + dd);
                std::reverse(s2.begin(), s2.end());
                if (s1 == s2) ans++;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
