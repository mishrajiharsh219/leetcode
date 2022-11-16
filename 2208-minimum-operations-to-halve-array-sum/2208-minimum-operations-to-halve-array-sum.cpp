class Solution {
public:
    int halveArray(vector<int>& nums) {
        priority_queue<double> pq;
        double sum=0;
        for(auto x:nums){
            sum+=double(x);
        }
       double half=sum/2.0;
        int ans=0;
        for(auto x:nums)
               pq.push(double(x));
        
        vector<double> row;
        
       while(sum>half){
            ans++;
           double top=pq.top()/2.0;
           pq.pop();
           pq.push(top);
           sum=sum-top;
       }
        return ans;
    }
};