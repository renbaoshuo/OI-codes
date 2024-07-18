#include <iostream>
#include <deque>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 2e6 + 5;

int n, k, a[N];
std::deque<int> q;  // 双端队列

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];

    for (int i = 1; i <= n; i++) {
        // 首先，代码使用一个 while 循环来维护一个单调递减的队列 q。
        // 在每次循环中，代码检查当前元素 a[i] 是否大于队列中最后一个元素 a[q.back()]。
        // 如果是，则将队列中最后一个元素出队，直到队列为空或者当前元素不大于队列中最后一个元素。
        // 这样可以确保队列中的元素始终保持单调递减的顺序。
        // 想一想：每次入队的元素都比前面的元素小，那么整个队列就一定是单调递减的。
        while (!q.empty() && a[q.back()] < a[i]) q.pop_back();

        q.push_back(i);

        // 然后，代码检查队列 q 的第一个元素是否在当前窗口内。
        // 如果队列的第一个元素的索引小于等于 i - k，则说明该元素已经不在当前窗口内，需要将其出队。
        // （其实不会出现小于的情况）
        // 这样可以确保队列中的元素始终是当前窗口内的元素。
        if (q.front() <= i - k) q.pop_front();

        if (i >= k) cout << a[q.front()] << endl;
    }

    return 0;
}
