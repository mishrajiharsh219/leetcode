class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        int n=nums.size();
        vector<int> ans;
        unordered_map<int,int> mp;
        for(int i=-50;i<=50;i++)
            mp[i]=0;
        for(int i=0;i<k-1;i++)
            mp[nums[i]]++;
        
        for(int i=k-1;i<n;i++)
        {
          mp[nums[i]]++;
            int cnt=0;
          for(int j=-50;j<=50;j++)
          {
              cnt+=mp[j];
              if(cnt>=x)
              {
                  if(j>=0)
                      ans.push_back(0);
                  else
                      ans.push_back(j);
                  break;
              }
          }
          mp[nums[i-k+1]]--;
        }
        return ans;
    }
};