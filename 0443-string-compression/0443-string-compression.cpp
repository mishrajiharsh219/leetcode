class Solution {
public:
    int compress(vector<char>& chars) {
      	if(chars.size() < 2)
            return chars.size(); 
        
	    string ans="";
        int count=1;
        for(int i=0;i<chars.size();i++){
            
            while(i<chars.size()-1 and chars[i]==chars[i+1]){
                i++;
                count++;
            }
            ans+=chars[i];
            if(count<2)
                continue;
            else{
                ans+=to_string(count);
                count=1;
            }
            
        }
        
        chars.clear();
        for(int i=0;i<ans.size();i++){
            chars.push_back(ans[i]);
        }
        return chars.size();
    }
};