#include <algorithm>
#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 105;

struct node {
    std::string name, help;
    int id, cnt;

    node()
        : id(0), cnt(0) {}
} a[N];

int n;

int main() {
    std::ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].name >> a[i].help;
        a[i].id = i;
        for (int j = 2; j < a[i].help.size(); j++) {
            if (a[i].help[j - 2] == 's' && a[i].help[j - 1] == 'o' && a[i].help[j] == 's') a[i].cnt++;
        }
    }
    std::sort(a + 1, a + 1 + n, [](node a, node b) -> bool {
        return a.cnt == b.cnt ? a.id < b.id : a.cnt > b.cnt;
    });
    int ans = 0, last = a[1].cnt;
    while (a[++ans].cnt == last) {
        cout << a[ans].name << ' ';
    }
    cout << endl
         << last << endl;
    return 0;
}
