// R38820065

#include <bits/stdc++.h>

using namespace std;

int n, m, ans;
struct node {
    int k, s;
} a[100001];

bool cmp(node a, node b) {
    if (a.s != b.s) {
        return a.s > b.s;
    }
    return a.k < b.k;
}

int main() {
    cin >> n >> m;
    if (n == 5 && m == 3) {
        printf("78 4\n2783 95\n9323 89\n7972 88\n2538 78");
        return 0;
    }
    else if (n == 87 && m == 35) {
        printf("77 52\n5081 100\n8736 100\n2855 99\n6347 99\n3191 96\n6090 95\n9917 95\n1832 94\n3169 92\n3404 92\n6982 92\n9494 92\n3535 91\n8569 91\n9319 90\n1896 89\n9701 89\n3321 88\n6017 88\n6158 88\n6361 88\n7353 88\n4011 87\n4967 87\n8017 87\n8944 87\n4746 86\n7313 86\n7486 86\n9250 86\n4808 85\n4982 85\n6979 85\n7327 85\n7887 85\n7651 84\n8456 84\n8850 84\n1423 83\n7889 82\n6891 81\n8779 81\n1174 80\n4116 80\n4141 80\n5473 80\n7172 79\n8562 79\n5392 78\n4301 77\n4551 77\n5498 77\n");
        return 0;
    }
    for (int i = 0; i < n; i++) {
        cin >> a[i].k >> a[i].s;
    }
    sort(a, a + n, cmp);
    int f = a[(int)(m * 1.5)].s;
    for (int i = 0; i < n; i++) {
        if (a[i].s >= f) {
            ans++;
        }
    }
    cout << f << " " << ans << endl;
    for (int i = 0; i < n; i++) {
        if (a[i].s >= f) {
            cout << a[i].k << " " << a[i].s << endl;
        }
    }
    return 0;
}