// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Function to determine if graph can be coloured with at most M colours such
// that no two adjacent vertices of graph are coloured with same colour.

bool isvalid(int node,bool graph[101][101],int k,int color[],int n){
    for(int p=0;p<n;p++){
        if(p!=node and color[p]==k and graph[p][node]==1)
        return false;
    }
    return true;
}

bool solve(int node,bool graph[101][101],int m,int n, int color[]){
if(node==n){
    return true;
}
for(int k=1;k<=m;k++){
if(isvalid(node,graph,k,color,n))
{
color[node]=k;
if(solve(node+1,graph,m,n,color))return true;
color[node]=0;
}
}
return false;
}

bool graphColoring(bool graph[101][101], int m, int n) {
    int color[n]={0};
    if(solve(0,graph,m,n,color))
    return true;
    else
    return false;
}

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        cout << graphColoring(graph, m, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends