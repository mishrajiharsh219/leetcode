class Solution {
public:
    bool valid(int mid,vector<int> &potions,long long success,int spell)
    {
        long long ans=(long long int)potions[mid]*(long long int)spell;
        if(ans>=success)
            return true;
        return false;
    }
    int bs(int spell,vector<int> &potions,long long success)
    {
        int n=potions.size();
    int ans=0;
    int low=0;
    int high=n-1;
        while(low<=high)
        {
        int mid=low+(high-low)/2;
        if(valid(mid,potions,success,spell))
        {
           high=mid-1;
        }
            else
            {
                low=mid+1;
            }
            ans = n-1-high;
        }   
        return ans;
    }
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n=spells.size();
        vector<int> ans(n,0);
        sort(potions.begin(),potions.end());
        for(int i=0;i<n;i++)
        {
        ans[i]=bs(spells[i],potions,success);
        }
        return ans;
    }
};