class Solution {
public:
    long long findScore(vector<int>& nums) {
     int n=nums.size();
        set<pair<int,int>> s;
        for(int i=0;i<n;i++)
        {
            s.insert({nums[i],i});
        }
        long long ans=0;
        for(auto c:s)
        {
            if(nums[c.second])
            {
                nums[c.second]=0;
                if(c.second-1>=0) nums[c.second-1]=0;
                if(c.second+1<nums.size()) nums[c.second+1]=0;
                ans+=c.first;
            }
        }
        return ans;
    }
};