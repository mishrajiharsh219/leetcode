class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int> mp;
        int n=fruits.size();
        int ans=0;
        int left=0;
        int right=0;
        while(left<n and right<n){
           mp[fruits[right]]++; 
           
            while(mp.size()>2){
                if(mp[fruits[left]]==1){
                    mp.erase(fruits[left]);
                }
                else
                {
                    mp[fruits[left]]--;
                }
                left++;
            }   
          ans=max(ans,right-left+1);
        right++;
        }
        return ans;
    }
};