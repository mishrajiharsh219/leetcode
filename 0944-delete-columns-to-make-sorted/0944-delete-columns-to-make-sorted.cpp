class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n=strs.size();
int ans=0;
        int m=strs[0].length();
        for(int i=0;i<m;i++){
            string s="",temp="";
            for(int j=0;j<n;j++){
                s+=strs[j][i];
            }
             temp=s;
            sort(temp.begin(),temp.end());
            if(temp!=s)
                 ans++;
            cout<<s;
        }
        return ans;
    }
};