class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n=gain.size();
        int ans=0;
        vector<int>res(n+1);
        for(int i=0;i<gain.size();i++)
        {    res[i+1]=gain[i]+res[i];
         cout<<res[i+1]<<" ";
         ans=max(res[i+1],ans);
        }
        return ans;
    }
};