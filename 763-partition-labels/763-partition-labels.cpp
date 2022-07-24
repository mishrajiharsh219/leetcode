// Fundamental idea is that if two instances of characters should be in the same partition.
// So, we start with the first character and see at what point we can finish the partition.
// The earliest we can do is at the last instance of this character.
// What if we find a character between the first character and the last instance of it?
// In this case, we increase the length of the partition. Why?
// If we do not increase the partition, the new character ends up into two partitions, which violates the constraint of the problem.
// If we have gone through all the characters between the start of partition and maximum of the last instance of characters, we can close the partition and start a new one.



class Solution {
public:
    vector<int> partitionLabels(string s) {
		// vector for keeping the track of  last occurence of every character
        vector<int> end_idx(26,0);
        
        for(int i = 0; i < s.length(); ++i)
            end_idx[s[i] - 'a']  = i;
        
        vector<int> res;
        
        int start = 0, end = 0;
		// scanning string character by character
        for(int i = 0; i < s.length(); ++i)
        {
		// whenever we get an character we check,
		// last index of that character
            end = max(end, end_idx[s[i] - 'a']);
            
			// when current i.e i == end
			// add it to result
            if( i == end)
            {
                // all the characters of current partition included
                res.push_back(i - start + 1);
				// update the start pointer for fresh start
                start = i + 1;
            }
        }
        
        return res;
    }
};