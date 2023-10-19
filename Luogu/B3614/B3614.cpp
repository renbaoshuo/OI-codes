#include <iostream>
#include <stack>

using std::cin;
using std::cout;
const char endl = '\n';

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;

    cin >> t;

    while (t--) {
        int n;
        std::stack<unsigned long long> st;

        cin >> n;

        while (n--) {
            std::string op;

            cin >> op;

            if (op == "push") {
                unsigned long long x;

                cin >> x;

                st.emplace(x);
            } else if (op == "pop") {
                if (st.empty()) {
                    cout << "Empty" << endl;
                } else {
                    st.pop();
                }
            } else if (op == "query") {
                if (st.empty()) {
                    cout << "Anguei!" << endl;
                } else {
                    cout << st.top() << endl;
                }
            } else if (op == "size") {
                cout << st.size() << endl;
            }
        }
    }

    return 0;
}
