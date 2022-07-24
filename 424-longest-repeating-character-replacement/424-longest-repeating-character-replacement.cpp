// - Scan the array with 2 pointers: left and right
// - Store the frequency of each character
// - Compute the replacement cost: cells count between left and right pointers - the highest frequency
// - if the replacement cost <= k: update longest string size
// - if the replacement cost > k: decrease frequency of character at left pointer; increase left pointer and repeat
// - - - Since we are looking for the longest sub-string, we don't need to shrink the sliding window by more than 1 character:
// - - - When we reach a window of size W, we know that our target window size is higher or equal to the current one ( >= W).
// - - - Therefore, we could continue sliding with a window of W cells until we find a larger window > W.

class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> counts(26, 0);
        int start = 0;
        int maxCharCount = 0;
        int n = s.length();
        int result = 0;
        for(int end = 0; end < n; end++){
            counts[s[end]-'A']++;
            if(maxCharCount < counts[s[end]-'A']){
                maxCharCount = counts[s[end]-'A'];
            }
            while(end-start-maxCharCount+1 > k){
                counts[s[start]-'A']--;
                start++;
                for(int i = 0; i < 26; i++){
                    if(maxCharCount < counts[i]){
                        maxCharCount = counts[i];
                    }
                }
            }
            result = max(result, end-start+1);
        }
        return result;
    }
};