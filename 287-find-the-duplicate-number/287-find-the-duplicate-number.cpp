class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int ans=0;
   vector<int> dup(nums.size());
        for(int i=0;i<nums.size();i++){
            dup[nums[i]]++;
        }
        for(int i=0;i<dup.size();i++){
            if(dup[i]>1)
                ans=i;
        }
        return ans;
    }
};