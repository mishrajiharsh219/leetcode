class Solution {
public:
    int totalSteps(vector<int>& nums) {
         stack<pair<int,int>> st;
        st.push({nums[0],0});

        int ans = 0;

        for(int i = 1;i < nums.size();i++){ 
            int cnt = 0;

            while(!st.empty() &&  st.top().first <= nums[i]){ 
                cnt = max(cnt,st.top().second);
                st.pop();
            }

            if(!st.empty()) cnt += 1;
            else cnt = 0;

            ans = max(ans,cnt);
            st.push({nums[i],cnt});
        }

        return ans;
    }
};