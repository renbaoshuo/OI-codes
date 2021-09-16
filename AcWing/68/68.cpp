class Solution {
  public:
    int getMissingNumber(vector<int>& nums) {
        set<int> s;
        for (int i = 0; i <= nums.size(); i++) {
            s.insert(i);
        }
        for (int i : nums) {
            s.erase(i);
        }
        return *s.begin();
    }
};
