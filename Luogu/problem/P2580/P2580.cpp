#include <bits/stdc++.h>

using namespace std;

int n, m;
string s;

struct node {
    bool flag[2];
    node* next[26];

    ~node() {
        for (auto& i : next) {
            delete i;
        }
    }
};

void insert(node* root, string s, bool type) {
    node* p = root;
    while (!s.empty()) {
        if (p->next[s[0] - 'a'] == nullptr) {
            p->next[s[0] - 'a'] = new node();
        }
        p = p->next[s[0] - 'a'];
        s = s.substr(1);
    }
    p->flag[type] = true;
}

inline int query(node* root, string s) {
    node* p = root;
    while (!s.empty()) {
        if (p->next[s[0] - 'a'] == nullptr) {
            return 0;
        }
        p = p->next[s[0] - 'a'];
        s = s.substr(1);
    }
    return p->flag[1] ? 2 : 1;
}

int main() {
    node* root = new node();
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s;
        insert(root, s, 0);
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> s;
        switch (query(root, s)) {
            case 0:
                cout << "WRONG" << endl;
                break;
            case 1:
                cout << "OK" << endl;
                break;
            case 2:
                cout << "REPEAT" << endl;
                break;
        }
        insert(root, s, 1);
    }
    delete root;
    return 0;
}
