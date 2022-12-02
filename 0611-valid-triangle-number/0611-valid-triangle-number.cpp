class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int ans=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0)//no side can be zero of a triangle
                continue;
            int start=i+1,end=i+2;
            for(start=i+1;start<nums.size();start++){
                while(end<nums.size() and nums[i]+nums[start]>nums[end])
                {
                    end++;
                }
                ans+=end-start-1;
            }
        }
        return ans;
    }
};