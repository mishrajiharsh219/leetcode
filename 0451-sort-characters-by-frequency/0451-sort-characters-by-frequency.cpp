class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mp;
        for(auto c:s)
            mp[c]++;
        
        priority_queue<int> q;
        
        for(auto x:mp){
            q.push(x.second);
        }
        
        string res="";
        
        while(!q.empty()){
            int m=q.top();
            q.pop();
           for(auto x:mp){
             if(x.second==m){
                 for(int i=0;i<m;i++)
                 res+=x.first;
                 mp.erase(x.first);
                 break;
             }
            }   
          }
        return res;
    }
};