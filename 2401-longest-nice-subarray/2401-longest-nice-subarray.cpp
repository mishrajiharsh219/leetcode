class Solution {
public:
    //CHECKS AND RETURNS FALSE WHEN A BIT OF NUMBER A ALREADY PRESENT IN VECTOR VIS
    bool check(int a , vector<int> &vis){
        for(int i = 0 ; i < 32 ; i++){
            if(((a>>i)&1) == 1 and vis[i]==1){
                return false;
            }
        }
        return true;
    }
    //FILL THE BITS OF A IN VIS
    void fill(int a , vector<int> &vis){
        for(int i = 0 ; i < 32 ; i++){
            if(((a>>i)&1) == 1){
                vis[i]=1;
            }
        }
    }
    //REMOVE BITS OF A NUMBER 'A' FROM VIS VECTOR
    void clear(int a , vector<int> &vis){
        for(int i = 0 ; i < 32 ; i++){
            if(((a>>i)&1) == 1){
                vis[i]=0;
            }
        }
    }
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();
        int i = 0  , j = i+1 , maxlen = 1;
        vector<int> vis(32,0);
        fill(nums[0],vis);
        
        while(i<n and j<n){

            // checking if window is as per requirement
            while(!check(nums[j],vis) and i<j){
                clear(nums[i],vis);
                i++;
            }    

            // filling window
            if(check(nums[j],vis)){
                fill(nums[j],vis);
                j++;
                maxlen = max(maxlen,j-i);
            }
        }
        
        return maxlen;
    }
};