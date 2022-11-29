class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        if(nums.size()==1)
            return 1;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int ans=1;
        int min=nums[0];
        for(int i=1;i<n;i++){
            if((nums[i]-min)<=k){
                continue;
            }
            else{
                min=nums[i];
                ans++;
            }
        }
        return ans;
    }
};