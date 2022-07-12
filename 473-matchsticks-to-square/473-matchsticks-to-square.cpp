//splitting an array of matches into 4 subsets where:
//mutually exclusive ,no specific element of array is shared bby any two subsets.
//4 subsets should have same sum


class Solution {
public:
    bool solve(int ind,vector<int> &sum,int sidelength,vector<int> &matchsticks){
        if(ind>=matchsticks.size()){
            if(sum[0]==sum[1]&&sum[1]==sum[2]&&sum[2]==sum[3]&&sum[3]==sidelength)
                return true;
        }
        for(int i=0;i<4;i++){
            if((sum[i]+matchsticks[ind])>sidelength)continue;
            sum[i]+=matchsticks[ind];
            if(solve(ind+1,sum,sidelength,matchsticks))
                return true;
            sum[i]-=matchsticks[ind];
            
        }
        return false;
    }
    
    bool makesquare(vector<int>& matchsticks) {
        int sum1=0;
        for(int i=0;i<matchsticks.size();i++)
        {
            sum1+=matchsticks[i];
        }
        if(sum1%4!=0)
            return false;
        sum1=sum1/4;
        sort(matchsticks.rbegin(),matchsticks.rend());
        vector <int> sum(4);
        
        return solve(0,sum,sum1,matchsticks);

        }
};