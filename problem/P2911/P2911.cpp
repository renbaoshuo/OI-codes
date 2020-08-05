// RR36448329

#include <bits/stdc++.h>

using namespace std;

int s1, s2, s3;

int main() {
    scanf("%d%d%d", &s1, &s2, &s3);
    if(s3 > s1 + s2) {
        printf("%d", s1+s2+1);
    } else if(s2 > s1 + s3) {
        printf("%d", s1+s3+1);
    } else if(s1 > s3 + s2) {
        printf("%d", s3+s2+1);
    } else {
        printf("%d", (s1+s2+s3+3)/2);
    }
    return 0;
}
