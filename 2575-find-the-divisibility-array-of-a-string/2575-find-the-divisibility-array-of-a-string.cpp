// //any number when divided by m=> n=q*m+r;
// now to add any digit by its last means multiplying it by 10 and then adding new digit d
// so new number =10*n+d;
// putting values, 10(q*m+r)+d;
// 10qm+10r+d
// now 10qm is already divisble by m so check (10r+d) for every d;

class Solution {
public:
    vector<int> divisibilityArray(string w, int m) {
        vector<int> ans(w.length(),0);
        long long rem=0;
        for(int i=0;i<w.length();i++)
        {
            rem=(rem*10+(w[i]-'0'))%m;
            if(rem ==0)
                ans[i]=1;
        }
        return ans;
    }
};