class Solution {
public:
    int minPartitions(string n) {
        int m=n.size();
        int maxi=0;
        for(int i=0;i<m;i++){
            int c=int(n[i])-48;
            maxi=max(maxi,c);
         }
        return maxi;
    }
};