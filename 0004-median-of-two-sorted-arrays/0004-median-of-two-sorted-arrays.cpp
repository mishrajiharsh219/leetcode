class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        int finalsize=n+m;
        int i=0,j=0,k=0;
        vector<int> merged(finalsize,-1);
        while(i<n and j<m){
            if(nums1[i]<nums2[j])
            merged[k++]=nums1[i++];
            else
            merged[k++]=nums2[j++];    
        }
        if(i<n){
            while(i<n)
            merged[k++]=nums1[i++];
        }
        if(j<m){
            while(j<m)
            merged[k++]=nums2[j++];
        }
        if(finalsize%2==1){
            return merged[((finalsize+1)/2)-1];
        }
           return ((float)merged[(finalsize/2)-1]+(float)merged[(finalsize/2)])/2;
    }
};