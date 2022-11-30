class Solution {
public:
    vector<bool> ans;
    void helper(vector<int> &nums,int i,int j){
        vector<int> temp;
        
        for(int k=i;k<=j;k++)
            temp.push_back(nums[k]);
        
        if(temp.size()<=1)
        {
            ans.push_back(false);
             return;
        }
        
        sort(temp.begin(),temp.end());
        
        for(auto x:temp)
            cout<<x<<" ";
        
        set<int> s;
        s.clear();
        for(int i=1;i<temp.size();i++){
            s.insert(temp[i]-temp[i-1]);
        }
        // cout<<s.size()<<" ";
        
        if(s.size()==1)
        { ans.push_back(true);
         return;
        }
        
        ans.push_back(false);
    }
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        for(int i=0;i<l.size();i++){
            helper(nums,l[i],r[i]);
        }
        return ans;
    }
};