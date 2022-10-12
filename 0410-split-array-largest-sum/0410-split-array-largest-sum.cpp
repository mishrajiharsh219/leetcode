class Solution {
public:
    bool valid(vector<int> nums,int k,int curr_min){
   int n=nums.size();
        int grpreq=1;
        int currsum=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>curr_min)
                return false;
            else if(currsum+nums[i]>curr_min){
                grpreq++;
                currsum=nums[i];
                if(grpreq>k)
                    return false;
            }
            else{
                currsum+=nums[i];
            }
        }
        return true;
    }
    
    int splitArray(vector<int>& nums, int k) {
        long long sum=0;
        
        int maxi=INT_MIN;
        for(int i=0;i<nums.size();i++)
            maxi=max(maxi,nums[i]);
        
        int low=maxi;
        
        for(int i=0;i<nums.size();i++)
            sum+=nums[i];
        
        int high=sum;
        
        int res=0;
        
        while(low<=high){
            int mid=low+(high-low)/2;
            if(valid(nums,k,mid)){
                res=mid;
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return res;
    }
};