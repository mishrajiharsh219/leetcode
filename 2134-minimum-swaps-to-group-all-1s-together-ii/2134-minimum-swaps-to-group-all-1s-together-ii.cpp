class Solution {
public:
    int minSwaps(vector<int>& nums) {
        vector<int> temp;
        int n=nums.size();
        for(int i=0;i<n;i++)
            temp.push_back(nums[i]);
        for(int i=0;i<n;i++)
            temp.push_back(nums[i]);
        // for(auto c:temp)
        //     cout<<c<<" ";
        int numofones=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==1)
                numofones++;
        }
        if(numofones<=1)
            return 0;
        int k=numofones;
        int numofwindows=2*n-k+1;
        int maxones=0;
        for(int i=0;i<k;i++)
        {
            if(temp[i]==1)
                maxones++;
        }
        int ans=maxones;
        for(int i=1;i<numofwindows;i++)
        {
        if(temp[i-1]==1)maxones--;
        if(temp[i+k-1]==1)maxones++;
            ans=max(ans,maxones);
        }
        return k-ans;
    }
};