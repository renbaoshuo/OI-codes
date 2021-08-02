#include <bits/stdc++.h>

using namespace std;

int main() {
    double a, b, c, d, x, y, z;
    cin >> a >> b >> c >> d;
    x = (2.00 * a + 3.00 * b + 4.00 * c + 1.00 * d) / 10.00;
    printf("Media: %.1lf\n", x + 0.01);
    if (x >= 7.0)
        cout << "Aluno aprovado." << endl;
    else if (x < 5.0)
        cout << "Aluno reprovado." << endl;
    else {
        cout << "Aluno em exame." << endl;
        cin >> y;
        printf("Nota do exame: %.1lf\n", y + 0.01);
        z = (x + y) / 2;
        if (z >= 5.0)
            cout << "Aluno aprovado." << endl;
        else
            cout << "Aluno reprovado." << endl;
        cerr << z << endl;
        printf("Media final: %.1lf\n", z);
    }
    return 0;
}
