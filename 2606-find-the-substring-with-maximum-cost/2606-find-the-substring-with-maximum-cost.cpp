class Solution {
public:
    int maximumCostSubstring(string s, string chars, vector<int>& value) {
        unordered_map<char,int> mp;
        int n=s.length();
        for(auto c:s)
        {
            mp[c]=int(c)+1-int('a');
        }
        for(int i=0;i<chars.size();i++)
        {
            mp[chars[i]]=value[i];
        }
        // for(auto it=mp.begin();it!=mp.end();it++){
        //     cout<<it->first<<" "<<it->second<<" ";
        //     cout<<endl;
        // }
        int sum=0;
        int ans=0;
       for(char c : s) {
            sum += mp[c];
            ans = max(ans, sum);
            if(sum < 0) sum = 0; 
        }
        return ans;
    }
};