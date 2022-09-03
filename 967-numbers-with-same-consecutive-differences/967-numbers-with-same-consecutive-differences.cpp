class Solution {
public:
    void backtrack(set<int> &res,string curr,int n,int k){
        if(curr.size()==n){
            res.insert(stoi(curr));
            return;
        }
        for(int i=0;i<=9;i++){
            if(curr[0]=='0')
                continue;
            if(abs((int(curr[curr.size()-1])-int('0'))-i)==k){
                curr+=to_string(i);
                backtrack(res,curr,n,k);
                curr=curr.substr(1);
            }
        }
    }
    vector<int> numsSameConsecDiff(int n, int k) {
          set<int> res;
        string curr;
        for(int i=1;i<=9;i++){
            curr+=to_string(i);
            backtrack(res,curr,n,k);
            curr=curr.substr(1);
        }
        for(auto c: res){
            cout<<c<<" ";
        }
     vector<int> res1(res.begin(),res.end());
        return res1;
    }
};