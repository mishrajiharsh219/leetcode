class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        int n=arr.size();
        int left=0;
        int right=arr.size()-1;
        sort(arr.begin(),arr.end());
        int med=arr[(n-1)/2];
        
        vector<int> ans(k);
        int cnt=0;
        while(cnt<k){
            
            int lefty=abs(arr[left]-med);
            int righty=abs(arr[right]-med);
            
            if(righty>=lefty)
            {
                ans[cnt]=arr[right];
                right--;
            }
            else{
                ans[cnt]=arr[left];
                left++;
            }
            
            cnt++;
        }
        return ans;
    }
};