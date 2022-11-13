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
        if(source.first==destination.first && source.second==destination.second){
            return 0;
        }
        if(grid[source.first][source.second]==0  || grid[destination.first][destination.second]==0){
            return -1;
        }
        
        int rows=grid.size();
        int cols=grid[0].size();
        vector<vector<int>> dist(rows,vector<int>(cols,INT_MAX)); 
       queue<pair<int,pair<int,int>>> pq;
        dist[source.first][source.second]=0;
        pq.push({0,{source.first,source.second}});
       
        
        int delrow[] = {-1, 0, +1, 0};   
        int delcol[] = {0, 1, 0, -1};
        
        while(!pq.empty()){
            int dis=pq.front().first;
            int row=pq.front().second.first;   
            int col=pq.front().second.second;
            pq.pop();
            for(int i=0;i<4;i++){
                int nRow=row+delrow[i];
                int nCol=col+delcol[i];
                
                if(nRow>=0 && nRow<rows && nCol>=0 && nCol<cols && grid[nRow][nCol]==1  && dis+1<dist[nRow][nCol]){
                
                        dist[nRow][nCol]=dis+1;
                        if(nRow==destination.first && nCol==destination.second){
                            return dis+1;
                        }
                        pq.push({dis+1,{nRow,nCol}});
                 
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