class Solution {
public:
    string reorganizeString(string s) {
        char common;
        int n=s.length();
        unordered_map<char,int> mp;
        for(auto c:s)
        {
            mp[c]++;
        }
        priority_queue<pair<int,char>> pq;
        for(auto c:mp)
        {
            pq.push({c.second,c.first});
        }
        string ans;
        char prev;
        while(!pq.empty())
        {
            char curr=pq.top().second;
             auto temp=pq.top();
            pq.pop();
             
            if(prev!=curr){
             ans.push_back(curr);
                temp.first--;  
                prev=curr;
             }
            else{
            if(!pq.empty()){
                char secchoice=pq.top().second;
                ans.push_back(secchoice);
                auto tempsec=pq.top();
                tempsec.first--;
                pq.pop();
                prev=secchoice;
                if(tempsec.first>0)
                pq.push(tempsec);
            }  
            else if(pq.empty())
                return "";
            }
            if(temp.first>0)
             pq.push(temp);
        }
        return ans;
    }
};