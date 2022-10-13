class Solution {
public:
    int sum(vector<int> &arr,int target, int mid){
        int sum=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]>=mid)
                sum+=mid;
            else
                sum+=arr[i];
        }
        return abs(sum-target);
    }
    int findBestValue(vector<int>& arr, int target) {
        int n=arr.size();
        sort(arr.begin(),arr.end());
        int res=0;
        int low=0;
        int high=1e8;
        while(low<=high){
            int mid=low+(high-low)/2;
            int e1=sum(arr,target, mid);
            int e2=sum(arr,target,mid+1);
                if(e1<=e2){
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