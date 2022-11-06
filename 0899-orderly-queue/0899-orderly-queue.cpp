class Solution {
public:
    string orderlyQueue(string s, int k) {
        if(k==1){
           int n=s.size();
            s=s+s;
            string ans=s;
            for(int i=0;i<n;i++){
                string st=s.substr(i,n);
                if(st<ans){
                    ans=st;
                }
            }
            return ans;
        }
        else
            sort(s.begin(),s.end());
        return s;
    }
};