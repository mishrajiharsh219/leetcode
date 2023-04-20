class Solution {
public:
    int addMinimum(string s) {
        int n = s.size(), i = 0, result = 0;
        while (i < n) {
            string s2 = s.substr(i, 2);
            if (s.substr(i, 3) == "abc") {
                i += 3;
            } else if (s2 == "ab" || s2 == "ac" || s2 == "bc") {
                i += 2;
                result += 1;
            } else {
                i += 1;
                result += 2;
            }
        }
        return result;
    }
};