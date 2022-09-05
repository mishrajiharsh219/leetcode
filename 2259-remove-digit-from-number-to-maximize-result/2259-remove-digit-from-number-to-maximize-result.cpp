class Solution {
public:
    string removeDigit(string number, char digit) {
        vector<string> nums;
        for(int i=0;i<number.size();i++){
            if(number[i]==digit){
                string a=number.substr(0,i);
                string b=number.substr(i+1,number.size()-1);
                string c=a+b;
                nums.push_back(c);
            }
        }
        sort(nums.begin(),nums.end());
        string ans=nums[nums.size()-1];
        return ans;
    }
};