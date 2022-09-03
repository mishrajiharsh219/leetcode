// The question wanted you to play with XOR. We will be using the fact that x^x = 0 and x^y = y^x.
// Lets consider the 2nd example where encoded = [6, 5, 4, 6]. Now, our array will have 5 elements, let's take them as [a, b, c, d, e]
// Now,

// [a^b,    b^c,   c^d,   d^e]		
// [ 6       5      4      6 ]
				
// Now, let us consider the XOR of all the permutation. Lets say it X. So,

// X = a^b^c^d^e
// Just add some brackets, and this X(better than mine \U0001f611) will become

// X = a ^    (b^c)     ^   (d^e)
// X = a ^ (encoded[1]) ^ (encoded[3])

// => a = X ^ (encoded[1] ^ encoded[3])
// We can observe that a, which is the first number, is actually XOR of permutation xored to the odd positioned elements of encoded vector.

// Thus, we can find the first number, and then from the first number, we can find the rest of them.
// Since we have a^b and a, thus, a^(a^b) = b, then from b and b^c, we find c and so on.
class Solution {
public:
    vector<int> decode(vector<int>& encoded) {
       vector<int> perm(encoded.size()+1,0);
        int x=0;
        for(int i=1;i<=encoded.size()+1;i++){
            x=x^i;
        }
        perm[0]^=x;
        for(int i=0;i<encoded.size();i++){
            if(i%2!=0){
                perm[0]^=encoded[i];
            }
        }
        for(int i=1;i<perm.size();i++){
        perm[i]^=encoded[i-1]^perm[i-1]; 
        }
        return perm;
    }
};