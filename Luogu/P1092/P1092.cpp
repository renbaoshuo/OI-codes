#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 30;

int n;
bool vis[N];
std::string s1, s2, s3;
std::map<char, int> map;
std::vector<char> chs;

bool check() {
    for (int i = n - 1; i >= 0; i--) {
        if (map[s1[i]] != -1 && map[s2[i]] != -1 && map[s3[i]] != -1) {
            if ((map[s1[i]] + map[s2[i]]) % n != map[s3[i]]
                && (map[s1[i]] + map[s2[i]] + 1) % n != map[s3[i]]) {
                return false;
            }
        } else if (map[s1[i]] != -1 && map[s2[i]] != -1) {  // map[s3[i]] == -1
            if (vis[(map[s1[i]] + map[s2[i]]) % n]
                && vis[(map[s1[i]] + map[s2[i]] + 1) % n]) {
                return false;
            }
        } else if (map[s1[i]] != -1 && map[s3[i]] != -1) {  // map[s2[i]] == -1
            if (vis[(map[s3[i]] - map[s1[i]] + n) % n]
                && vis[(map[s3[i]] - map[s1[i]] - 1 + n) % n]) {
                return false;
            }
        } else if (map[s2[i]] != -1 && map[s3[i]] != -1) {  // map[s1[i]] == -1
            if (vis[(map[s3[i]] - map[s2[i]] + n) % n]
                && vis[(map[s3[i]] - map[s2[i]] - 1 + n) % n]) {
                return false;
            }
        }
    }

    return true;
}

bool check_ans() {
    int x = 0;

    for (int i = n - 1; i >= 0; i--) {
        if ((x + map[s1[i]] + map[s2[i]]) % n != map[s3[i]]) {
            return false;
        }

        x = (x + map[s1[i]] + map[s2[i]]) / n;
    }

    return x == 0;
}

void dfs(int x) {
    if (x == n) {
        if (check_ans()) {
            for (auto o : map) {
                cout << o.second << ' ';
            }

            cout << endl;

            exit(0);
        }

        return;
    }

    for (int i = n - 1; i >= 0; i--) {
        if (vis[i]) continue;

        vis[i] = true;
        map[chs[x]] = i;

        if (check()) dfs(x + 1);

        map[chs[x]] = -1;
        vis[i] = false;
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> s1 >> s2 >> s3;

    for (int i = n - 1; i >= 0; i--) {
        if (!map.count(s1[i])) {
            map[s1[i]] = -1;
            chs.emplace_back(s1[i]);
        }

        if (!map.count(s2[i])) {
            map[s2[i]] = -1;
            chs.emplace_back(s2[i]);
        }

        if (!map.count(s3[i])) {
            map[s3[i]] = -1;
            chs.emplace_back(s3[i]);
        }
    }

    dfs(0);

    return 0;
}
