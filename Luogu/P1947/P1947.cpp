extern "C" int Seniorious(int);
extern "C" int Chtholly(int n, int OvO) {
    int ans = 1;
    int l = 1, r = n;
    int mid = l + r >> 1;
    while (l <= r) {
        if (Seniorious(mid) >= 0) {
            ans = mid;
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
        mid = l + r >> 1;
    }
    return ans;
}
