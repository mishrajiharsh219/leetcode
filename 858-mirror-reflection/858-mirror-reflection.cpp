//if we extend the square we can see that the the p=3 and q=2 case meets 0 
//it satisfies condition 2*p=3*q
//extension*p=reflection*q is satisfied in all conditions
//if ext =even and ref=odd then res=0
//if ref=even and ext=odd then res=1
//if ref=odd and ext=odd then res=1
class Solution {
public:
    int mirrorReflection(int p, int q) {
        int ext=q,ref=p;
        while(ext%2==0 and ref%2==0)
        {
            ext/=2;
            ref/=2;
        }
        if(ext%2==0 and ref%2!=0)return 0;
        if(ext%2!=0 and ref%2==0) return 2;
        if(ext%2!=0 and ref%2!=0) return 1;
        return -1;
    }
};