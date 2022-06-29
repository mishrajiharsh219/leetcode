class Solution {
public:
    int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        int res=0,res1=0;
        for(int i=0;i<arr1.size();i++){
            res=arr1[i]^res;
        }
         for(int i=0;i<arr2.size();i++){
            res1=arr2[i]^res1;
        }
        int ans=res&res1;
        return ans;
    }
};