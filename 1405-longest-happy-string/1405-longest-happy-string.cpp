class Solution {
public:
  
    string longestDiverseString(int a, int b, int c) {
       string res="";
            priority_queue<pair<int,char>> pq;
        if(a)
            pq.push({a,'a'});
        if(b)
            pq.push({b,'b'});
        if(c)
            pq.push({c,'c'});
        
        while(pq.size()>1){
            pair<int, char> one=pq.top();
            pq.pop();
            pair<int,char> two=pq.top();
            pq.pop();
            
            if(one.first>=2){
            res+=one.second;
            res+=one.second;
            one.first=one.first-2;
            }
            
            else{
                res+=one.second;
                one.first-=1;
            }
            if(two.first>=2 and two.first>=one.first){
                res+=two.second;
                res+=two.second;
                two.first-=2;
            }
            
            else{
                res+=two.second;
                two.first-=1;
            }
            
            if(one.first>0)
                pq.push(one);
            if(two.first>0)
                pq.push(two);
        }
        if(pq.empty())
            return res;
        if(pq.top().first>=2)
        {   res+=pq.top().second;
            res+=pq.top().second;}
        else
            res+=pq.top().second;
    return res;
    }             
};
