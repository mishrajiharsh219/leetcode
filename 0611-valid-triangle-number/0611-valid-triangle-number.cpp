class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int count=0;
        sort(nums.begin(),nums.end());
          for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 0) continue;
               int start = i + 1, end = i + 2;
          for (int start = i + 1; start < nums.size(); ++start) {
            while (end < nums.size() && nums[i] + nums[start] > nums[end]) {
                ++end;
            }
            count += end - start - 1;
        }
          }
            return count;
    }
};