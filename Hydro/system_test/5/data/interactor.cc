#include <iostream>

#include "testlib.h"

using namespace std;

int main(int argc, char* argv[]) {
    setName("Interactor A+B");
    registerInteraction(argc, argv);

    // reads number of queries from test (input) file
    int a = inf.readInt();
    int b = inf.readInt();
    // writes query to the solution, endl makes flush
    cout << a << " " << b << endl;
    int ans;
    cin >> ans;
    if (a + b == ans)
        quitf(_ok, "!");
    else
        quitf(_wa, "?");
}
