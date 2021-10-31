#include <bits/stdc++.h>

using namespace std;

time_t getTime() {
    tm t;
    scanf("%d-%d-%d-%d:%d", &t.tm_year, &t.tm_mon, &t.tm_mday, &t.tm_hour, &t.tm_min);
    t.tm_year -= 1900;
    t.tm_mon -= 1;
    t.tm_isdst = t.tm_sec = 0;
    return mktime(&t);
}

int main() {
    time_t time_start, time_end, time_left;
    int n, a[5005], ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    time_start = getTime();
    time_end = getTime();
    time_left = (time_end - time_start) / 60;
    sort(a, a + n);
    for (int i = 0; i < n; i++) {
        time_left -= a[i];
        if (time_left < 0) break;
        ans++;
    }
    cout << ans << endl;
    return 0;
}
