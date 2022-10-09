class Solution {
public:
    static bool cmp(vector<int> &a,vector<int> &b){
        if(a[0]<b[0])
            return a>b;
        else
           return b>a;
    }
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n=intervals.size();
        vector<int> res(intervals.size(),-1);
        map<int,int> index;
        int i=0;
        for(auto x: intervals){
            index[x[0]]=i++;
        }
        for(int i=0;i<intervals.size();i++){
            if(index.lower_bound(intervals[i][1])!=index.end())
                res[i]=index.lower_bound(intervals[i][1])->second;
            //we cant use . becouse it is pointing to an interator
        }
       
        return res;
        
    }
};