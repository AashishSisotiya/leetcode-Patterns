//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        vector<pair<int,int>> adj[n+1];
        ///first create a adjacency list
        for(auto it:edges){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        
        //this question is the slight change in the standard dijkastra algorithm 
        // we have to keep track of the node from which we are coming 
        // for that we will use a parent array 
        
        priority_queue<pair<int,int>,vector<pair<int,int>> , greater<pair<int,int>>> pq;
        vector<int> dist(n+1,1e9),parent(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
        pq.push({0,1});
        dist[1]=0;
        
        while(!pq.empty()){
            int dis =pq.top().first;
            int node=pq.top().second;
            pq.pop();
            
            for(auto it:adj[node]){
                 int adjNode=it.first;
                 int edgWt=it.second;
                 if(edgWt+dis<dist[adjNode]){
                     dist[adjNode]=dis+edgWt;
                     pq.push({dist[adjNode],adjNode});
                     parent[adjNode]=node;
                 }
            }
        }
        if(dist[n]==1e9){
            return {-1};
        }
        int node =n;
        vector<int> ans;
        while(parent[node]!=node){
         ans.push_back(node);
         node=parent[node];
         
        }
        ans.push_back(1);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends