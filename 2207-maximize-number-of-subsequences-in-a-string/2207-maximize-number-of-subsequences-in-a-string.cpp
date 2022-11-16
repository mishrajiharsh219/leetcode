class Solution {
public:
    long long finans(string t,string pat){
        long long total=0;
        long long secondchar=0;
        int n=t.size();
        for(int i=n-1;i>=0;i--){
            int flag=0;
            if(t[i]==pat[1]){
                secondchar++;
                flag=1;
            }
         if(t[i]==pat[0]){
                total+=secondchar;
            }
            if(flag and pat[0]==pat[1]){
                total--;
            }
        }
        return total;
    }
    long long maximumSubsequenceCount(string text, string pattern) {
        long long ans=0;
        ans=max(finans(pattern[0]+text,pattern),finans(text+pattern[1],pattern));
        return ans;
    }
};