class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int> mp;
        for(auto c:tasks){
            mp[c]++;
        }
   long long int ans=0;
        for(auto c:mp){
            int temp=c.second;
                if(temp==1)
                    return -1;
                
                else if(temp%3==0){
                    ans+=temp/3;
                }
                else{
                   int grpofthree=temp/3;
                    if(temp%3==1)
                        grpofthree--;
                    if(temp%3==1)
                    ans+=grpofthree+2;
                    else
                    ans+=grpofthree+1;
                }
        }
        return ans;
    }
};