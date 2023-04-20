class Solution {
public:
    vector<string> ans;
    void solve(int ind,string s,unordered_map<string,int> &mp,string temp)
    {
        if(ind==s.size())
        { temp.pop_back();
            ans.push_back(temp);
            return;
        }
        for(int i=ind;i<s.size();i++)
        {
            string temp1=s.substr(ind,i-ind+1);
            if(mp.find(temp1)!=mp.end())
            {
                temp1=temp1+" ";
                solve(i+1,s,mp,temp+temp1);
            }
        }
        return;
     }
    vector<string> wordBreak(string s, vector<string>& word) {
        int n=s.size();
        unordered_map<string,int> mp;
        for(auto c:word)
        {
        mp[c]++;  
        }
        string temp="";
        solve(0,s,mp,temp);
        return ans;
    }
};