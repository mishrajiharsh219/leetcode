class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int n=nums.size();
        int m=queries.size();
        vector<int> ans(m);
        sort(nums.begin(),nums.end());
        for(int i=1;i<n;i++){
            nums[i]=nums[i]+nums[i-1];
        }
        for(int i=0;i<m;i++){
         vector<int> ::iterator l1;
        l1=upper_bound(nums.begin(),nums.end(),queries[i]);
            ans[i]=l1-nums.begin();
        }
        return ans;
    }
};