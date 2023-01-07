class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
         int n=gas.size();
        int tank=0,start=0,total=0;
        //pass2 if soln exists
        for(int i=0;i<n;i++){
            total=total+gas[i]-cost[i];
        }
        if(total<0)
            return -1;
        //pass1 to fid unique start
        for(int i=0;i<n;i++){
            tank+=gas[i]-cost[i];
            if(tank<0)
            {
                start=i+1;
                tank=0;
                
            }
        }
        return start;
    }
};