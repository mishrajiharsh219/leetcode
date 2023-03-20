class Solution {
public:
    bool canPlaceFlowers(vector<int>& bed, int n) {
        int count=0;
        for(int i=0;i<bed.size();i++)
        {
            if(bed[i]==0)
            {
                bool prev=false,next=false;
                
                if(i==0)
                    prev=true;
                 if(i==bed.size()-1)
                    next=true;
                
                if(i-1>=0 and bed[i-1]==0)
                    prev=true;        
                if(i+1<bed.size() and bed[i+1]==0)
                    next=true;
        
                if(prev and next)
                {
                    bed[i]=1;
                    count++;
                }
            }
        }
        if(count>=n)
            return true;
        return false;
    }
};