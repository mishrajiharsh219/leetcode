class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        if(n==0)
            return 0;
        vector<int> temp;
        temp.push_back(nums[0]);
        for(int i=1;i<n;i++)
        {
            if(nums[i]>temp.back())
            {
                temp.push_back(nums[i]);
            }
            else
            {
                int pos=lower_bound(temp.begin(),temp.end(),nums[i])-temp.begin();
                temp[pos]=nums[i];
            }
        }
        return temp.size();
    }
};