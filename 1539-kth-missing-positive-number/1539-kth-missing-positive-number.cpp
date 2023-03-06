class Solution {
public:
    //arr[mid]==mid+1 in ideal case
    //arr[mid]-(mid+1) will give missing elements till now
    //missing elements just greater than k will come at low;
    int findKthPositive(vector<int>& arr, int k) {
        int l=0,h=arr.size()-1;
        while(l<=h)
        {
            int mid=(l+h)/2;
            if(arr[mid]-(mid+1)<k)
                l=mid+1;
            else
                h=mid-1;
        }
        return l+k;
    }
};