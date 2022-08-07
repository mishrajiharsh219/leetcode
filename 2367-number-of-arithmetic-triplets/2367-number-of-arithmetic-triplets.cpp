class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    if((i<j) and (j<k) and (nums[j]-nums[i]==diff) and (nums[k]-nums[j]==diff))
                        ans++;
                }
            }
        }
        return ans;
    }
};