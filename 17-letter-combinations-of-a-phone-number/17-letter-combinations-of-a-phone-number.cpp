class Solution {
public:
    void helper(vector<string> &res,string &digits,map<int,string> &mp,string &ds,int i){
       if(i==digits.size())
       {
           res.push_back(ds);
           return;
       }
        for(char c: mp[int(digits[i])-int('0')]){
            ds+=c;
            helper(res,digits,mp,ds,i+1);
            ds.pop_back();
        }
        return;
    }
    vector<string> letterCombinations(string digits) {
         if(digits=="")
             return {};
        map<int,string> mp;
        mp[2]="abc";
        mp[3]="def";
        mp[4]="ghi";
        mp[5]="jkl";
        mp[6]="mno";
        mp[7]="pqrs";
        mp[8]="tuv";
        mp[9]="wxyz";
        vector<string> res;
        string ds="";
        helper(res,digits,mp,ds,0);
        return res;
    }
};