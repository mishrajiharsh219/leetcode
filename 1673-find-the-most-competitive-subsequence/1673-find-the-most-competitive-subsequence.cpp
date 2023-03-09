class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        int n=nums.size();
        stack<int> s;
        for(int i=0;i<n;i++)
        {
            while(!s.empty() and s.top()>nums[i] and (s.size()-1+nums.size()-i)>=k)
                s.pop();
            if(s.size()<k)
                s.push(nums[i]);
        }
        vector<int> ans;
        while(!s.empty())
        {
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};