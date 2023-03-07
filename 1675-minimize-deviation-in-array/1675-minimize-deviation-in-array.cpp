// max deviation=(max-min);
// decrease max and increase min to get minimum deviation
// even cant be increased
// odd cant be decreased
// termination condition will be when min becomes even and max becomes odd
// that will be our best minimum deviation

class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int n=nums.size();
        priority_queue<int> pq;
        int maxe=INT_MIN,mine=INT_MAX;
        for(int i=0;i<n;i++)
        {
            if(nums[i]%2==1)
            {
                nums[i]=nums[i]*2;
            }
            maxe=max(maxe,nums[i]);
            mine=min(mine,nums[i]);
            pq.push(nums[i]);
        }
        int ans=maxe-mine;
        while(pq.top()%2==0)
        {
            int temp=pq.top();
            pq.pop();
            ans=min(ans,temp-mine);
            mine=min(mine,temp/2);
            pq.push(temp/2);
        }
        ans=min(ans,pq.top()-mine);
        return ans;
    }
};