class Solution {
public:
    bool isPowerOfFour(int n){
        return n>0 and ((n&(n-1))==0) and ((n & 0xAAAAAAAA)==0);
    }
};

// Explanation:
// A number which is a power of 4 has binary representation like this:
// 000...1000000...
// There's only a single 1 bit. The number of zeros after the bit 1 must be an even number. 4^0 = 1 (1), 4^1 = 4 (100), 4^2 = 16 (10000). When we multiply a number by 4, we shift it left by 2 which means adding 2 more zeros after the 1 bit. In other words, the 1 bit must be in an even position.

// To check if there's only a single bit 1: num & (num - 1) == 0. According to Cracking the Coding Interview's explanation:

// A & B == 0 means that A and B never have a 1 bit in the same place.
// When you subtract 1 from a number, you look at the least significant bit. If it's a 1 you change it to 0, and you are done. If it's a zero, you must "borrow" from a larger bit. So, you go to increasingly larger bits, changing each bit from a 0 to a 1, until you find a 1. You flip that 1 to a 0 and you are done. Thus, n-1 will look like n, except that n's initial 0s will be 1 s in n-1, and n's least significant 1 will be a 0 in n-1. That is: if n = abcde1000 then n-1 = abcde0111.
// Recall that n and n-1 never have a 1 bit in the same place. n and n-1 have the same part in their binary representation: abcde. We can conclude that abcde = 00000, which means n = 00000...1000...
// Actually this is a way to check if n is a power of 2 (or if n is 0).

// How about (num & 0xAAAAAAAA) == 0? 0xAAAAAAAA is 10101010‭10101010101010101010101010101010‬ in binary. ANDing a 32-bit number with 0xAAAAAAAA means setting all even bits to 0. After clearing even bits, if the number is larger than 0, it means the 1 bit is in an odd position and num is just a power of 2. Otherwise num is a power of 4 (or a zero).

// Finally, remember to check num > 0.