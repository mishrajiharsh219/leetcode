class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=1;
        int count=0,j=0;
     for(int i=1;i<nums.size()-1;i++){
         if(nums[i]==nums[i-1] and nums[i]==nums[i+1])
         {
             nums.erase(nums.begin()+i);
             i--;
         }
     }
        return nums.size();
    }
};