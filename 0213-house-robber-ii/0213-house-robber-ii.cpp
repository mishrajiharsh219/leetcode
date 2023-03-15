class Solution {
public:
    int maxi(vector<int> &nums)
    {
        int n=nums.size();
        int prev2=0;
        int prev=nums[0];
        int curr=nums[0];
        for(int i=1;i<n;i++)
        {
            int take=nums[i];
            if(i>=2)
                take+=prev2;
            int notake=0 + prev;
            curr=max(take, notake);
            prev2=prev;
            prev=curr;
        }
        return curr;
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
            return nums[0];
        vector<int> temp1,temp2;
        for(int i=0;i<n;i++)
        {
            if(i!=0)
                temp1.push_back(nums[i]);
            if(i!=n-1)
                temp2.push_back(nums[i]);
        }
        int ans1=maxi(temp1);
        int ans2=maxi(temp2);
        return max(ans1,ans2);
    }
};