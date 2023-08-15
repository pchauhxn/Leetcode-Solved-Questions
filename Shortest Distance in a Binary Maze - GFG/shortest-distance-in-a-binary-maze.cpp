//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        // code here
        if(source==destination)
            return 0;
        if(grid[source.first][source.second]==0)
            return -1;
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> dist(m,vector<int>(n,1e9));
        dist[source.first][source.second]=0;
        queue<pair<int,pair<int,int>>>pq;
        pq.push({0,{source.first,source.second}});
        int delr[]={-1,0,1,0};
        int delc[]={0,1,0,-1};
        while(!pq.empty()){
            auto node=pq.front();
            int row=node.second.first;
            int col=node.second.second;
            int dis=node.first;
            pq.pop();
            for(int i=0;i<4;i++){
                    int nrow=row+delr[i];
                    int ncol=col+delc[i];
                        if(nrow<m && ncol<n && nrow>=0 && ncol>=0 && grid[nrow][ncol]==1 && (dis+1)<dist[nrow][ncol]){
                            dist[nrow][ncol]=dis+1;
                            if(nrow==destination.first && ncol==destination.second)
                                return dis+1;
                            pq.push({dis+1,{nrow,ncol}});
                    }
            }
        }
        return -1;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends