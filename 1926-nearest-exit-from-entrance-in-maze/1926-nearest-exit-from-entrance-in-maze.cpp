class Solution {
public:
       bool isvalid(int n,int m,int row,int col)
    {
        if(row>=0 and row<n and col>=0 and col<m)
        {
            return true;
        }
        return false;
    }
    int nearestExit(vector<vector<char>>& arr, vector<int>& ent) 
    {
        int n=arr.size();
        int m=arr[0].size();

        queue<pair<int,int>>q;
        q.push({ent[0],ent[1]}); 
        arr[ent[0]][ent[1]]='+';

        int steps = 0;
        while(!q.empty())
        {
            int size = q.size();
            for(int i=0;i<size;i++)
            {
                pair<int,int>p = q.front();
                q.pop();

                int x = p.first;  
                int y = p.second; 
                if((x==0 or y==0 or x==n-1 or y==m-1))
                {
                    if((x!=ent[0] or y!=ent[1]))
                        return steps;
                }

                if(isvalid(n,m,x+1,y)==true and arr[x+1][y]!='+')
                {
                    arr[x+1][y]='+';
                    q.push({x+1,y});
                }
                if(isvalid(n,m,x-1,y)==true and arr[x-1][y]!='+')
                {
                    arr[x-1][y]='+';
                    q.push({x-1,y});
                }
                if(isvalid(n,m,x,y+1)==true and arr[x][y+1]!='+')
                {
                    arr[x][y+1]='+';
                    q.push({x,y+1});
                }
                if(isvalid(n,m,x,y-1)==true and arr[x][y-1]!='+')
                {
                    arr[x][y-1]='+';
                    q.push({x,y-1});
                }
            }
            steps++;
        }
        return -1;
    }
};