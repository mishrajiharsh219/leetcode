class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> mp;
        int n=s.length();
        for(int i=0;i<n;i++){
            mp[s[i]]++;
        }
        int ans=0;
        for(auto count: mp){
            if((count.second)%2==0)
                ans+=count.second;
            else
                ans+=count.second-(count.second%2);
        }
        if(ans<n)            //we can put one in middle
        return ans+1;
        else
            return ans;
    }
};