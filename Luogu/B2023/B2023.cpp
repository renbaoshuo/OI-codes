#include <iostream>
#include <iomanip>

using std::cin;
using std::cout;
const char endl = '\n';

char a;
int b;
float c;
double d;

int main() {
    std::ios::sync_with_stdio(false);
    cin >> a >> b >> c >> d;
    cout << a << ' ' << b << ' ' << std::fixed << std::setprecision(6) << c << ' ' << std::fixed << std::setprecision(6) << d << endl;
    return 0;
}
