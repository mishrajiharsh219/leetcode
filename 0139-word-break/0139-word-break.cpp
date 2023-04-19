class Solution {
public:
    bool solve(int ind,string s,unordered_map<string,int> &mp,vector<int> &dp)
    {
        if(ind==s.size())
        {
            return true;
        }
        if(dp[ind]!=-1)
            return dp[ind];
        bool ans=false;
        for(int i=ind;i<s.size();i++)
        {
            string temp=s.substr(ind,i-ind+1);
            if(mp.find(temp)!=mp.end())
            {
                ans=solve(i+1,s,mp,dp);
                if(ans==true)
                    return ans;
            }
        }
        return dp[ind]=ans;
    }
    bool wordBreak(string s, vector<string>& words) {
        int n=s.size();
        unordered_map<string,int> mp;
        vector<int> dp(n,-1);
        for(auto c:words)
        {
            mp[c]=1;
        }
         return solve(0,s,mp,dp);
    }
};