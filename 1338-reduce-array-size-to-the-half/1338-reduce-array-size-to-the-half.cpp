class Solution {
public:
    // static bool cmp(int &a, int &b){
    //     if()
    // }
    int minSetSize(vector<int>& arr) {
        set<int> ans;
        int n=arr.size();
        int size=n;
        map<int,int> mp;
        for(int i=0;i<n;i++){
          mp[arr[i]]++;  
        }
     priority_queue<pair<int,int>> pq;
        for(auto c:mp){
            pq.push(make_pair(c.second,c.first));
        }
        while(size>n/2){
             pair<int,int> b=pq.top();
        cout<<b.first<<" "<<b.second; 
            size-=b.first;
            ans.insert(b.second);
            pq.pop();
        }
        return ans.size();
    }
};