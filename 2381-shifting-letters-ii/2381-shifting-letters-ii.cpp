class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> sum(n+1, 0);
        for(int i = 0; i<shifts.size(); i++){
            int x = shifts[i][0], y = shifts[i][1]+1;
            int dir = shifts[i][2];
            if(dir == 1){
                sum[x] +=1;
                sum[y] -= 1;
            }
            else{
                sum[x] -=1;
                sum[y] +=1;
            }
        }
        for(int i = 1; i<=n; i++){
            sum[i] += sum[i-1];
        }
        for(int i = 0; i<n; i++){
            int a = sum[i];
            if(a<0){
                int b = abs(a)%26;
                a = s[i]-'a'+26-b;
                s[i] = 'a'+a%26;
            }   
            else{
                a += s[i]-'a';
                s[i] = 'a' + a%26;
            }
        }
        return s;

    }
};
