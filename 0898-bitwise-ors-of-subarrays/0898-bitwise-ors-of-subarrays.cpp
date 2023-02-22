class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        int n=arr.size();
        set<int> s;
        for(int i=0;i<n;i++)
        {
            int curr=arr[i];
            int prev=0;
            int j=i-1;
            s.insert(curr);
            while(j>=0 and curr!=prev)
            {
                prev=prev|arr[j];
                curr=curr|arr[j];
                s.insert(curr);
                j--;
            }
        }
        return s.size();
    }
};