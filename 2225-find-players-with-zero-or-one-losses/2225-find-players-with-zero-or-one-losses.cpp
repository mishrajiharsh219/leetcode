class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        int n=matches.size();

        unordered_map<int,int>mp1;
        unordered_map<int,int>mp2;

        for(int i=0 ; i<n ; i++){
            mp1[matches[i][0]]++;
            mp2[matches[i][1]]++;
        }

       vector<vector<int>>ans;
        vector<int>temp;
        vector<int>temp1;

       for(auto pr:mp1) {
           if(mp2.find(pr.first)==mp2.end()){temp.push_back(pr.first);}
       }
        sort(temp.begin(),temp.end());
        ans.push_back(temp);


        for(auto pr:mp2){
            if(pr.second==1){temp1.push_back(pr.first);}
        }
        sort(temp1.begin(),temp1.end());
        ans.push_back(temp1);

        return ans;
    }
};