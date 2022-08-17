class Solution {
public:
    vector<int> hour={1,2,4,8};
    vector<int> min={1,2,4,8,16,32};
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> res;
        pair<int,int> time;
        int num=turnedOn;
        helper(0,num,res,time);
        return res;
    }
    void helper(int starting,int num,vector<string> &res,pair<int,int> time){
        if(num==0){
            res.push_back(to_string(time.first)+(time.second<10 ? ":0" : ":")+ to_string(time.second));
            return;
        }
            
            for(int i=starting;i<(hour.size()+min.size());i++){
                if(i<hour.size()){
                  time.first+=hour[i];
                    if(time.first<12)
                        helper(i+1,num-1,res,time);
                    time.first-=hour[i];
                }
                else {
                    time.second+=min[i-hour.size()];
                    if(time.second<60)
                        helper(i+1,num-1,res,time);
                    time.second-=min[i-hour.size()];
                }
            }
    }
};

 