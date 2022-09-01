class Solution {
public:
    string largestPalindromic(string s) {
        map<char, int> mp;
        for(int i=0; i<s.length(); i++){// putting characters and their frequency in map
            mp[s[i]]++;
        }
        string ans;// final ans string
        map<char, int>::reverse_iterator it;
        //now in i am iterating from last, as map contains key in ascending order
        for (it = mp.rbegin(); it != mp.rend(); it++){ 
            if((*it).second>1 && (*it).second%2==0){
                // if curr char has even freq > 1
                // then i am adding those characters in middle                                 
                ans.insert(ans.length()/2, (*it).second, (*it).first);
                mp[(*it).first] = 0;// setting their freq to 0 as they are used
            }
            else if((*it).second>1 && (*it).second%2==1){
                // if curr char has odd freq > 1
                // then i am adding those characters in middle - only taking even freq 
                ans.insert(ans.length()/2, (*it).second-1, (*it).first);
                mp[(*it).first] = 1;// setting their freq to 1 (remaining freq)
            }
        }
        // now only the characters with 1 freq left in the map
        for (it = mp.rbegin(); it != mp.rend(); it++){
            // here to maximize the no. i am taking the recent char from back whose freq is 1
            if((*it).second == 1){
                ans.insert(ans.length()/2, 1, (*it).first);
                break;
            }
        }
        ans.erase(0, ans.find_first_not_of('0'));// removing the leading 0
        if(ans.length()==0) return "0";// if s = "0000"
        //also deleting the ending zeroes as they never made palindrome
        //ex : 090 = 9 : 900 is not a palindrome
        for(int i=ans.length()-1; i>=0; i--){
            if(ans[i]!='0'){
                return ans.substr(0 , i+1);
            }
        }
    return ans;
    }
};