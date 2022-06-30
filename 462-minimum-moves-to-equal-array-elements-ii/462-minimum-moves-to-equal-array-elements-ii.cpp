class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n=nums.size();
       sort(nums.begin(),nums.end());
        int ans=0;
        int med=nums[n/2];
        for(int i=0;i<n;i++){
            ans+=abs(nums[i]-med);
        }
        return ans;
    }
};

//for not median do: ans+=nums[right--]-nums[left++];