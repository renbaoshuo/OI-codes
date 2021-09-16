class Solution {
  public:
    int getNumberOfK(vector<int>& nums, int k) {
        int ans = 0;
        for (int i : nums) {
            ans += i == k;
        }
        return ans;
    }
};
