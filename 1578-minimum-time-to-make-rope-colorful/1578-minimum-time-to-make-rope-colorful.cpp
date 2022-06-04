class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int prevcost=0;
        char prev='+';
        int ans=0;
        for(int i=0;i<colors.size();i++){
            if(colors[i]==prev){
                if(prevcost<neededTime[i]){
                    ans+=prevcost;
                    prevcost=neededTime[i];   
                }
                else{
                    ans+=neededTime[i];
                }
            }
            else{
                prev=colors[i];
                prevcost=neededTime[i];
            }
        }
        return ans;
    }
};