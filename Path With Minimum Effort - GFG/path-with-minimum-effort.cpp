//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int MinimumEffort(vector<vector<int>>& heights) {
        // Code here
         int rows=heights.size();
        int cols=heights[0].size();

        vector<vector<int>> effort(rows,vector<int>(cols,INT_MAX));
         priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        pq.push({0,{0,0}});
        effort[0][0]=0;
        int delrow[]={-1,0,+1,0};
        int delcol[]={0,+1,0,-1};

        while(!pq.empty()){
            int efrt=pq.top().first;
            int row=pq.top().second.first;
            int col=pq.top().second.second;

            pq.pop();
            for(int i=0;i<4;i++){
                int nrow=row+delrow[i];
                int ncol=col+delcol[i];

                if(nrow>=0 && ncol>=0 && nrow<rows && ncol<cols){
                    int nefrt=abs(heights[nrow][ncol]-heights[row][col]);
                    int maxEfrt=max(nefrt,efrt);
                    if(maxEfrt<effort[nrow][ncol]){                     
                        effort[nrow][ncol]=maxEfrt;
                        pq.push({maxEfrt,{nrow,ncol}});
                    }
                }
            }
        }

        return effort[rows-1][cols-1]; 
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n,m; cin>>n>>m;
        vector<vector<int>> heights;
       
        for(int i=0; i<n; ++i){
            vector<int> temp;
            for(int j=0; j<m; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            heights.push_back(temp);
        }
       
        Solution obj;
        cout<<obj.MinimumEffort(heights)<<"\n";
    }
    return 0;
}
// } Driver Code Ends