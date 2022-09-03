class Solution {
public:
    int minCost(vector<int>& startpos, vector<int>& homepos, vector<int>& rowCosts, vector<int>& colCosts) {
        int startrow=startpos[0];
        int startcol=startpos[1];
        int homerow=homepos[0];
        int homecol=homepos[1];
        
        int ans=0;
        
        if(startrow<homerow){
        for(int i=startrow+1;i<=homerow;i++){
            
            ans+=rowCosts[i];
        }
        }
          if(startrow>homerow){
        for(int i=homerow;i<=startrow-1;i++){
            
            ans+=rowCosts[i];
        }
        }
        
        if(homecol>startcol)
         for(int i=startcol+1;i<=homecol;i++){
            ans+=colCosts[i];
        }
        else
         for(int i=homecol;i<=startcol-1;i++){
            ans+=colCosts[i];
        }
        return ans;
    }
};