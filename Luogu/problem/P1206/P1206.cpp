#include <bits/stdc++.h>

using namespace std;

class node {
  private:
    char c(int x) {
        if (0 <= x && x <= 9) {
            return x + '0';
        }
        return x - 10 + 'A';
    }
    int len;
    int nums[20];

  public:
    node() {
        len = 0;
    }
    node(int x, int b) {
        len = 0;
        while (x) {
            nums[len] = x % b;
            x /= b;
            len++;
        }
    }

    int& operator[](int x) {
        return nums[x];
    }

    string str() {
        string s;
        for (int i = len - 1; i >= 0; i--) {
            s.push_back(c(nums[i]));
        }
        return s;
    }
    bool check() {
        for (int i = 0; i < len; i++) {
            if (nums[i] != nums[len - i - 1]) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    int b;
    cin >> b;
    for (int i = 1; i <= 300; i++) {
        node t = node(i * i, b);
        if (t.check()) {
            cout << node(i, b).str() << ' ' << t.str() << endl;
        }
    }
    return 0;
}
