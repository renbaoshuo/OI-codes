#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

int cnt;
char s1, s2, s3,
    t1, t2, t3;

int main() {
    std::ios::sync_with_stdio(false);
    cin >> s1 >> s2 >> s3 >> t1 >> t2 >> t3;
    if (s1 != t1) cnt++;
    if (s2 != t2) cnt++;
    if (s3 != t3) cnt++;
    cout << (cnt == 0 || cnt == 3 ? "Yes" : "No") << endl;
    return 0;
}
