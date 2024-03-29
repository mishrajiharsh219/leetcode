class Solution {
public:
//     int f(string a,string b){
//         int s1=a.length();
//         int s2=b.length();
//         bool bits[26]={false};
//         for(char ch:a)
//             bits[ ch-'a'] = true;
//         for(char ch : b)
//            if( bits[ch-'a'] == true)return 0;
        
//         return s1*s2;
//     }
//     int maxProduct(vector<string>& words) {
//         int n=words.size();
//         int ans=0;
//         for(int i=0;i<n;i++){
//             for(int j=i+1;j<n;j++){
//                 ans=max(ans,f(words[i],words[j]));
//             }
//         }
//         return ans;
//     }
    int maxProduct(vector<string>& words) {
	int n = size(words), ans = 0;
	vector<bitset<26> > chars(n);
	for(int i = 0; i < n; i++) {
		for(auto& ch : words[i])  // map the letters to 1 if it occurs in the word
			chars[i][ch - 'a'] = 1;
		// now check with all other words and if there's no common letter, then update ans	
		for(int j = 0; j < i; j++)
			if(!checkCommon(chars[i], chars[j])) 
				ans = max(ans, int(size(words[i]) * size(words[j])));
	}   
	return ans;
}
// Returns true if there's a common letter between bitset of two words
bool checkCommon(bitset<26>& a, bitset<26>& b) {
	for(int i = 0; i < 26; i++) if (a[i] & b[i]) return true;
	return false;
}
};