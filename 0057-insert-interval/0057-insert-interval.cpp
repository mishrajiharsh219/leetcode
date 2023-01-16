class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newinterval) {
        int i=0;
        vector<vector<int>> res;
        
        for(int i=0;i<intervals.size();i++){
            
            if(intervals[i][1]<newinterval[0]){
                res.push_back(intervals[i]);
            }
            else if(intervals[i][0]>newinterval[1]){
                res.push_back(intervals[i]);
            }
            else{
            newinterval[0] = min(newinterval[0], intervals[i][0]);
            newinterval[1] = max(newinterval[1], intervals[i][1]);
            }
        }
        res.push_back(newinterval);
        sort(res.begin(),res.end());
        return res;
    }
};