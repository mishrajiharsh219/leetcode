class Solution {
public:

int maximumUniqueSubarray(vector<int>& nums) {
    int sum=0,left=0,right=0;
    int l=0,r=0;
    int n=nums.size();
    int res=0;
    unordered_map<int,int> mp;
    while(r<n){
        int right=nums[r++];
        sum+=right;
        mp[right]++;
        
        while(mp[right]>1){
            int left=nums[l++];
            mp[left]--;
              sum-= left;
        }
          res=max(res,sum);
    }
    return res;
} 
};