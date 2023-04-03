class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
       int ans=0;
        int n=people.size();
        if(n==0)
            return 0;
        if(n==1 and people[0]<=limit)
            return 1;
        if(n==1 and people[0]>limit)
            return 0;
        sort(people.begin(),people.end(),greater<int>());
        int i=0,j=n-1;
        while(i<=j)
        {
            if(people[i]+people[j]<=limit)
            {
                i++;
                j--;
                ans++;
            }
            else if(people[i]<=limit){
                i++;
                ans++;
            }
            else if(people[j]<=limit)
            {
            j--;
            ans++;
            }
        }
        return ans;
    }
};