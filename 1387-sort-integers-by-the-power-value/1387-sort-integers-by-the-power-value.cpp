class Solution {
public:
    unordered_map<int,int> mp;
    
    int traverse(int x){
        if(mp[x] or x==1)
            return mp[x];
        
        if(x % 2)
        mp[x] = 1+traverse(3*x + 1);
    else
        mp[x] = 1+traverse(x/2);
        
        return mp[x];
    }
    int getKth(int lo, int hi, int k) {
        vector<pair<int,int>> ans;
        
        for(int i=lo;i<=hi;i++){
            ans.push_back({traverse(i),i});
        }
        sort(ans.begin(),ans.end());
        return ans[k-1].second;
    }
};