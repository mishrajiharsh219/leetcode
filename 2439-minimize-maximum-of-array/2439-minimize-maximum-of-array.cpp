class Solution {
public:
    bool valid(int mid,vector<int> &nums)
    {
        long sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            if(sum>long(long(i+1)*mid))
                return false;
        }
        return true;
    }
    int minimizeArrayValue(vector<int>& nums) {
        int low=0;
        int high=*max_element(nums.begin(),nums.end());
        while(low<high)
        {
            int mid=(low+high)/2;
            if(valid(mid,nums))
            {
                high=mid;
            }
            else
                low=mid+1;
        }
        return low;
    }
};