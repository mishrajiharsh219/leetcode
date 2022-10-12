class Solution {
public:
    bool isvalid(vector<int> &position,int mid,int m){
        int balls=1;
        int currball=position[0];
        for(int i=1;i<position.size();i++){
            if(position[i]-currball>=mid){
                currball=position[i];
                balls++;
                if(balls>=m)
                    return true;
            }
        }
            if(balls>=m)
                return true;
        else
            return false;
    }
    int maxDistance(vector<int>& position, int m) {
      int ans=0;
        sort(position.begin(),position.end());
        int low=1;
        int high=position[position.size()-1]-position[0];
        while(low<=high){
            int mid=low+(high-low)/2;
            if(isvalid(position,mid,m)){
                ans=mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return ans;
    }
};