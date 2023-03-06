class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n=arr.size();
        int maxi=*max_element(arr.begin(),arr.end());
        vector<int> hash(maxi+1,0);
        for(int i=0;i<n;i++)
        {
            hash[arr[i]]=1;
        }
        long long int ans=1;
        for(int i=1;i<=maxi;i++)
        {
            if(hash[i]==0)
            {ans=i;
             k--;}
            if(k==0)
                return ans;
        }
        return maxi+k;
    }
};