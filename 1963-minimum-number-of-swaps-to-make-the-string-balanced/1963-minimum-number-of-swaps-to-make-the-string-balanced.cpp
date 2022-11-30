class Solution {
public:
    //First cancel out all the valid pairs, then you will be left with something like]]][[[, and the answer will be ceil(m/2). Where m is the number of pairs left.
    int minSwaps(string s) {
       if(s.length()==0)
           return 0;
        int stacksize=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='[')
                stacksize++;
            else
            {
                if (stacksize > 0)
                stacksize--;
            }
        }
        int ans=ceil((stacksize+1)/2);
        return ans;
    }
};