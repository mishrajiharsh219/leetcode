class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int prev=1,ans=0;
        int n=arr.size();
        int i=0;
        while(k>0 and i<n)
        {
            if(prev==arr[i])
                i++;
            else
                k--;
            ans=prev;
            prev++;
        }
        return k+ans;
    }
};