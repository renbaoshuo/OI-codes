#include <algorithm>
#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

const int ratings[] = {1200, 1400, 1600, 1900, 2100, 2300, 2400, 2600, 3000};

int r, x;

int main() {
    std::ios::sync_with_stdio(false);

    cin >> r;
    cout << *std::upper_bound(ratings, ratings + 9, r) << endl;

    return 0;
}
