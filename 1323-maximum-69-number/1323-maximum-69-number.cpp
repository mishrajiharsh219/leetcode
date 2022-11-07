class Solution {
public:
    int maximum69Number (int num) {
        string s=to_string(num);
        bool flag=false;
        int i=0;
        while(flag==false and i<s.length()){
            if(s[i]=='6')
            {
                s[i]='9';
                flag=true;
            }
            i++;
        }
        return stoi(s);
    }
};