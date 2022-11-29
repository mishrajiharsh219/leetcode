class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        int n=nums.size();
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
              mp[nums[i]]=i;
        }
        for(auto x:operations){
            if(mp.find(x[0])!=mp.end()){
                mp[x[1]]=mp[x[0]];
                mp.erase(x[0]);
            }
        }
        for(auto x:mp){
            nums[x.second]=x.first;
        }
        return nums;
    }
};