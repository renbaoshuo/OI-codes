class Solution {
  private:
    static bool cmp(int a, int b) {
        return a % 2 == b % 2 ? a < b : a % 2 == 1;
    }

  public:
    vector<int> reOrderArray(vector<int>& nums) {
        sort(nums.begin(), nums.end(), cmp);
        return nums;
    }
};
