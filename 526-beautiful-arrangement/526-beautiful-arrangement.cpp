class Solution {
public:
    int backtrack(vector<int> &nums,vector<int> &freq,int index,int n){
        if(index==n+1){
            return 1;
        }
        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(freq[i]==0 and (nums[i]%index==0 or index%nums[i]==0)){
                freq[i]=1;
                ans+=backtrack(nums,freq,index+1,n);
                freq[i]=0;
            }
        }
        return ans;
    }
    int countArrangement(int n) {
        vector<int> freq(n+1,0);
        vector<int> nums;
        for(int i=1;i<=n;i++){
            nums.push_back(i);
        }
       int ans= backtrack(nums,freq,1,n);
       return ans;
    }
};