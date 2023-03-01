class Solution {
public:
    int maxNumOfMarkedIndices(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int first=n/2-1;
        int second=n-1;
        int ans=0;
        while(first>=0 and second>=0)
        {
            if((2*nums[first])<=nums[second])
            {
                second--;
                ans++;
            }
            first--;
        }
        return ans*2;
    }
};