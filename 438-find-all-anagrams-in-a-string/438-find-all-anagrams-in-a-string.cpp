// Basically, you keep one hash to keep the every elements in p to compare with another hash that you'd use as window slide.

// Every time current index is more than window, we need to pop our hash window at front. So how we do this? we find what would be the front by using
// curr_index-window_size in hash to pop that. If the keyed-value is equal to 1, then we can delete the entire key from the existence, otherwise, we just reduce by 1.

// We directly compare phash to window hash if they are same -> if it is, then we take the beginning of the index of the window and moving on.

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        vector<int> hash(26, 0);
        vector<int> phash(26, 0);
        int window = p.size();
        int len = s.size();
        if(len < window)
        {
            return ans;
        }
        int left = 0,right = 0;
        while(right < window)
        {
            phash[p[right] - 'a'] += 1;
            hash[s[right] - 'a'] += 1;
            right++;
        }
        right -=1;
        while(right < len)
        {
            if(phash == hash)
            {
                ans.push_back(left);
            }
            right+=1;
            if(right != len)
            {
                hash[s[right] - 'a'] += 1;
            }
            hash[s[left] - 'a'] -=1 ;
            left += 1;
        }
        return ans;
    }
};