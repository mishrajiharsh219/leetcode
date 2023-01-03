class Solution {
public:
    vector<int> topStudents(vector<string>& pf, vector<string>& nf, vector<string>& report, vector<int>& student_id, int k) {
        int n = report.size();
        vector<pair<int ,int>>stu;
        unordered_map<string , int>mpf , mnf;
        for(int i=0;i<pf.size();i++) mpf[pf[i]]=3;
        for(int i=0;i<nf.size();i++) mnf[nf[i]]=-1;
        for(int i=0;i<n;i++){
            
            stringstream ss(report[i]);
            string word;
            int count=0;
            
            while (ss >> word){
                count+=(mpf[word]+mnf[word]);
            }
            stu.push_back({-count , student_id[i]});
            
        }
        sort(stu.begin() , stu.end());
        vector<int>ans;
        for(int i=0;i<k;i++){
            ans.push_back(stu[i].second);
        }
        return ans;
           
    }
};