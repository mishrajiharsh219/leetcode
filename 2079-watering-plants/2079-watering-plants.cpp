class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int ans=0;
        int i=0;
        int curr=capacity;
        while(i<plants.size()){
            if(curr>=plants[i]){
                ans++;
                curr-=plants[i];
                i++;
            }
            else{
                curr=capacity;
                curr-=plants[i];
                ans+=i+1;
                ans+=i;
                i++;
            }
            
        }
        return ans;
    }
};