class Solution {
public:
    static bool cmp(string a,string b)
    {
        if(a+b>b+a)
            return true;
        return false;
    }
    string largestNumber(vector<int>& nums) {
        vector<string> num(nums.size(),"");
        for(int i=0;i<nums.size();i++)
        {
            num[i]=to_string(nums[i]);
        }
        sort(num.begin(),num.end(),cmp);
        if(num[0]=="0")
            return "0";
        string ans;
        for(auto c:num)
            ans+=c;
        return ans;
    }
};