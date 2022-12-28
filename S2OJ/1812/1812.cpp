#include <iostream>
#include <algorithm>
#include <functional>
#include <iterator>
#include <numeric>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 5e4 + 5;
const int INF = 0x3f3f3f3f;

template <typename T>
struct Max {
    T operator()(T a, T b) const {
        return std::max(a, b);
    }
};

template <typename T>
struct Min {
    T operator()(T a, T b) const {
        return std::min(a, b);
    }
};

template <typename T, int N, class Operator = std::plus<int>>
class BIT {
  private:
    T default_val;
    T c[N];

    unsigned lowbit(unsigned x) {
        return x & -x;
    }

  public:
    BIT(const T& init_val = 0)
        : default_val(init_val) {
        std::fill(std::begin(c), std::end(c), init_val);
    }

    void add(unsigned x, T v) {
        for (; x < N; x += lowbit(x)) {
            c[x] = Operator()(c[x], v);
        }
    }

    T query(T x) {
        T res = default_val;

        for (; x; x -= lowbit(x)) {
            res = Operator()(res, c[x]);
        }

        return res;
    }
};

int n, k, a[N], s[N];

bool check(int x) {
    int res_min = 0,
        res_max = 0;
    std::vector<int> nums;
    BIT<int, N << 1, Max<int>> bit_max(-INF);
    BIT<int, N << 1, Min<int>> bit_min(INF);

    std::copy(s + 1, s + 1 + n, std::back_inserter(nums));
    std::transform(nums.begin(), nums.end(), nums.begin(), std::bind(std::minus<int>(), std::placeholders::_1, x));
    std::copy(s, s + n, std::back_inserter(nums));
    std::sort(nums.begin(), nums.end());
    nums.erase(std::unique(nums.begin(), nums.end()), nums.end());

    int pos = nums.size() - (std::lower_bound(nums.begin(), nums.end(), 0) - nums.begin() + 1) + 1;

    bit_min.add(pos, 0);
    bit_max.add(pos, 0);

    for (int i = 1; i <= n; i++) {
        pos = nums.size() - (std::lower_bound(nums.begin(), nums.end(), s[i] - x) - nums.begin() + 1) + 1;
        res_min = bit_min.query(pos);
        res_max = bit_max.query(pos);

        if (i < n) {
            pos = nums.size() - (std::lower_bound(nums.begin(), nums.end(), s[i]) - nums.begin() + 1) + 1;
            bit_min.add(pos, res_min + 1);
            bit_max.add(pos, res_max + 1);
        }
    }

    return ++res_min <= k && k <= ++res_max;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    std::partial_sum(a + 1, a + 1 + n, s + 1);

    int l = -INF,
        r = INF,
        ans = 0;

    while (l <= r) {
        int mid = (l + r) >> 1;

        if (check(mid)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    cout << ans << endl;

    return 0;
}
