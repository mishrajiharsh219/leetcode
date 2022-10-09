class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        if(pref.size()==1)
            return {pref[0]};
        vector<int> ans;
        ans.push_back(pref[0]);
        int temp;
        ans.push_back(pref[0]^pref[1]);
        int low=ans[0]^ans[1];
        for(int i=2;i<pref.size();i++){
            temp=low^pref[i];
            ans.push_back(temp);
            low=low^temp;
        }
        return ans;
    }
};