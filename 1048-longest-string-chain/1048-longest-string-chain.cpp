class Solution {
public:
    static bool cmp(string &a,string &b)
    {
        return a.size()<b.size();
    }
    bool compare(string &a,string &b)
    {
        if(a.size()!=b.size()+1)
            return false;
        int first=0;
        int second=0;
        while(first<a.size())
        {
            if(second<b.size() and a[first]==b[second])
            {
                first++;
                second++;
            }
            else
            {
                first++;
            }
        }
        if(first==a.size() and second==b.size())
            return true;
        return false;
    }
    int longestStrChain(vector<string>& words) {
        int n=words.size();
        if(words.size()==0)
            return 0;
        vector<int> dp(n,1);
        sort(words.begin(),words.end(),cmp);
        int maxi=1;
        for(int i=0;i<n;i++)
        {
            for(int prev=0;prev<i;prev++)
            {
                if(compare(words[i],words[prev]))
                {
                    dp[i]=max(1+dp[prev],dp[i]);
                }
            }
            maxi=max(maxi,dp[i]);
        }
        return maxi;
    }
};