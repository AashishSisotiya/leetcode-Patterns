//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        queue<pair<int,int>> q;
        q.push({start,0});
        
        vector<int> dist(100000,INT_MAX);
        dist[start]=0;
        int mod=100000;
        
        // Tc ---->  100000 * sizeof(arr) = 100000 * 1000  // hypothetically
        // it is impossible to generate all the numbers between 1 to 100000 
        
        while(!q.empty()){
            int node=q.front().first;
            int moves=q.front().second;
            q.pop();
            
            for(auto it:arr){
                int num=(node*it)%mod;
                if(moves+1<dist[num]){
                    dist[num]=moves+1;
                    if(num==end)return moves+1;
                    
                    q.push({num,moves+1});
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
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends