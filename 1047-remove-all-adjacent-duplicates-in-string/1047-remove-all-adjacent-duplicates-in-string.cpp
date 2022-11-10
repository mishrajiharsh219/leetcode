class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        st.push(s[0]);
        int i=1;
        while(i<s.length()){
            if(st.empty()){
                st.push(s[i]);
                i++;
                continue;
            }
          char c=st.top();
          st.pop();
            if(s[i]==c){
                i++;
                continue;}
            else{
           st.push(c);
            st.push(s[i]);
                i++;
            }
        }
        string res;
        while(!st.empty()){
            res+=st.top();
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};