class Solution {
public:
    
//     calculate how many digits the number has.
// calculate what the number is.
// find out which digit in the number is we wanted.
    // 1->9 =9 digits
    // 10=>99=90 * 2 digits
    // 100->999=900*3 digits
        
    int findNthDigit(int n) {
        long long base=9;
        long long digits=1;
        while(n-base*digits>0)
        {
            n=n-base*digits;
            base=base*10;
            digits++;
        }
        // we are including 100 or 1000 or 1000 type starting number into pow so n-1;
        //digits-1 because range starts from there only
        
        long long number=pow(10,digits-1)+(n-1)/digits;
        long long index=(n-1)%digits;
        
        string ans=to_string(number);
        ans=ans[index];
        return stoi(ans);
    }
};