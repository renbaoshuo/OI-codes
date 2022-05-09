class Solution {
  public:
    int getSum(int n) {
        int r = n;
        n && (r += getSum(n - 1));
        return r;
    }
};
