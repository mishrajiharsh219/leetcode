class Solution {
public:
    int bitwiseComplement(int n) {
      int comp=1;// beacuse we cant use zero breacuse a<<b=a*2^b
     while(comp<n)
     {
        comp=comp<<1|1;   //when comp=1 then first comp becomes 10 then or by comp=1
         //in next step comp=110 | 1 = 111
     }
     return n^comp; // xor will transform all 1 in n into 0 and rest becomes 1   
    }
};