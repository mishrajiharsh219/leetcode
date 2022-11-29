class Solution {
public:
    //To find lattice points, we basically need to find values of (x, y) which satisfy the equation x2 + y2 = r2.
    // so for inside the circle x*x+y*y<=r*r
    int countLatticePoints(vector<vector<int>>& circles) {
        int cnt=0;
        for(int i=0;i<=200;i++)
            for(int j=0;j<=200;j++){
                for(auto &c:circles){
                    if(((c[0]-i)*(c[0]-i)+(c[1]-j)*(c[1]-j))<=(c[2]*c[2]))
                    {   cnt++;
                    break;}
                }
            }
        return cnt;
    }
};