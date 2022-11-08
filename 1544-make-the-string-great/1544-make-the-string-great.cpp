class Solution {
public:
    string makeGood(string s) {
        stack<char> st;
        string res;
        int i=1;
        st.push(s[0]);
        while(i<s.length()){
            char c;
            if(!st.empty())
              c=st.top();
            else
            {
                st.push(s[i]);
                i++;
                continue;
            }
            st.pop();
            if((isupper(c) and s[i]==tolower(c)) or (islower(c) and s[i]==toupper(c))){
                i++;
                continue;
            }
            st.push(c);
            st.push(s[i]);
            i++;
        }
        while(!st.empty()){
            res+=st.top();
          st.pop();
        }
        if(res=="")
            return "";
        reverse(res.begin(),res.end());
        return res;
    }
};