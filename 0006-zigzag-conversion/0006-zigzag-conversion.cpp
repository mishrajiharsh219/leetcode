class Solution {
public:
    //magic number=k=rows-1
    //if a number is divisble by magic number then shift will happen
    string convert(string s, int rows) {
        int rownum=0;
        int increase=-1;
        vector<string> res(rows);
        if(rows==1)
            return s;
        for(int i=0;i<s.length();i++){
        if(i%(rows-1)==0)
            increase*=-1;
        res[rownum].push_back(s[i]);
        rownum+=increase;
        }
        string ans;
        for(auto c:res){
         ans+=c;
        }
        return ans;
    }
};