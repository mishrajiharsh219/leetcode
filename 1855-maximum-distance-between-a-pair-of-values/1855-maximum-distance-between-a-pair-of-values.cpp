class Solution {
public:
    int maxj(int num,vector<int> &nums2){
        int low=0,high=nums2.size()-1;
int ans=0;
        while(low<=high){
            int mid=low-(low-high)/2;
            if(nums2[mid]>=num){
                low=mid+1;
                ans=mid;
            }
            else
               high=mid-1;
        }
        return ans;
    }
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        int real=INT_MIN;
        for(int i=0;i<n;i++){
            int ans=maxj(nums1[i],nums2);
            int res=ans-i;
            real=max(real,res);
        }
        return real;
    }
};