class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(n==1)
            return 1;
        vector<int> v(n+1,0);
        for(auto c:trust){
            int p1=c[0];
            int p2=c[1];
            v[p1]--;
            v[p2]++;
        }
        for(int i=1;i<(n+1);i++){
            if(v[i]==(n-1))
                return i;
        }
        return -1;
    }
};