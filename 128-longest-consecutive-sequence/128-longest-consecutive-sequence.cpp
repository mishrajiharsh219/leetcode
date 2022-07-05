class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> x;
        for(auto a:nums)
            x.insert(a);
        
        int t,l=0,ans=0;
        for(auto it:x)
        {
            if(l==0)
                l = 1;
            else
            {
                if(t+1==it)
                    l++;
                else
                {
                    ans = max(ans,l);
                    l = 1;
                }
            }
            t = it;
        }
        ans = max(ans,l);
        return ans;
    }
};
  