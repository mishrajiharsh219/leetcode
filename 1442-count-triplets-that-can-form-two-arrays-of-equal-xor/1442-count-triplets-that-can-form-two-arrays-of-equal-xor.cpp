class Solution {
public:
    int countTriplets(vector<int>& arr) {
     int ans = 0;
        int length = arr.size();
        for (int i = 0; i < length; i++) {
            int xoor = arr[i];
            for (int j = i + 1; j < length; j++) {
                xoor ^= arr[j];
                if (xoor == 0) {
                    ans += (j - i);
                }
            }
        }
        return ans;   
    }
};