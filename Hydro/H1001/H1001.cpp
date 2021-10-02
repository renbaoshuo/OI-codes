#include <bits/stdc++.h>

using namespace std;

struct node {
    int size;
    node* next[26];

    ~node() {
        for (auto& i : next) {
            delete i;
        }
    }
};

void insert(node* root, string s) {
    if (s.empty()) {
        root->size = 1;
        return;
    }
    if (root->next[s[0] - 'a'] == nullptr) root->next[s[0] - 'a'] = new node();
    insert(root->next[s[0] - 'a'], s.substr(1));
}

void calcsize(node* root) {
    for (int i = 0; i < 26; i++) {
        if (root->next[i] != nullptr) {
            calcsize(root->next[i]);
            root->size += root->next[i]->size;
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    int n;
    string s;
    node* root = new node();
    cin >> n;
    while (n--) {
        cin >> s;
        insert(root, s);
    }
    calcsize(root);
    cout << root->size << endl;
    delete root;
    return 0;
}
