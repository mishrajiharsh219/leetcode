class Solution {
public:
    int MOD=1e9+7;
    
   long long int rec(char c,int n,int i,vector<vector<int>> &dp,unordered_map<char,int> &mp){
     if(i==n)
        return 1;
        
    long long int count=0;
        
        if(dp[mp[c]][i]!=-1)
            return dp[mp[c]][i]%MOD;
        
        if(c=='a'){
            count+=rec('e',n,i+1,dp,mp);
        }
        
        else if(c=='e')
        {
            count+=rec('a',n,i+1,dp,mp);
            count+=rec('i',n,i+1,dp,mp);
        }
        else if(c=='u')
        {
            count+=rec('a',n,i+1,dp,mp);
        }
        else if(c=='o'){
            count+=rec('i',n,i+1,dp,mp);
            count+=rec('u',n,i+1,dp,mp);
        }
        else{
            count += rec('a',n,i+1,dp,mp);
            count += rec('e',n,i+1,dp,mp);
            count += rec('o',n,i+1,dp,mp);
            count += rec('u',n,i+1,dp,mp);
        }
        
        dp[mp[c]][i]=count%MOD;
        return dp[mp[c]][i]%MOD;
        
    }
    int countVowelPermutation(int n) {
        unordered_map<char,int>mp;
        mp['a']=0;
        mp['e']=1;
        mp['i']=2;
        mp['o']=3;
        mp['u']=4;
        vector<vector<int>> dp(5,vector<int>(n+1,-1));
        long long int res=0;
        res= rec('a',n,1,dp,mp)+rec('e',n,1,dp,mp)+rec('i',n,1,dp,mp)+rec('o',n,1,dp,mp)+rec('u',n,1,dp,mp);
        return res%MOD;
    }
};