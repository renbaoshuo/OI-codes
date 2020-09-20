// R38666209

#include <bits/stdc++.h>

using namespace std;

int main() {
    char c;
    int  cnt[30];
    memset(cnt, 0x00, sizeof(cnt));
    while (cin >> c) {
        cnt[c - 'A']++;
    }
    for (int i = 0; i <= 405; i++) {
        int flag = 0, max = 0, end = 0;
        for (int j = 0; j < 26; j++) {
            if (cnt[j] >= max) {
                max = cnt[j];
                end = j;
                if (max != 0) {
                    flag = 1;
                }
            }
        }
        if (flag == 0) {
            printf("A B C D E F G H I J K L M N O P Q R S T U V W X Y Z");
            break;
        }
        for (int j = 0; j <= end; j++) {
            if (cnt[j] == max) {
                printf("%s%c", j == 0 ? "" : " ", '*');
                cnt[j]--;
            }
            else {
                printf("%s%s", j == 0 ? "" : " ", " ");
            }
        }
        printf("\n");
    }
    return 0;
}
