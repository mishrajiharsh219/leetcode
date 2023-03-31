class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        if(arr.size()<3)
            return false;
        int n=arr.size();
        if(arr[0]>=arr[1])
            return false;
        int i=1;
        while(i<n-1 and arr[i]>arr[i-1])
        {
            i++;
        }
        while(i<n and arr[i]<arr[i-1])
        {
            i++;
        }
        return i==arr.size();
    }
};