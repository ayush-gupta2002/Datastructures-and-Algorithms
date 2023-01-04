//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        queue<pair<int,int>> q;
        vector<int> distance(100000,INT_MAX);
        distance[start] = 0;
        q.push({start,0});
        
        while(!q.empty()){
            pair<int,int> frontPair = q.front();
            q.pop();
            int factor = frontPair.first;
            int steps = frontPair.second;
            if(factor==end){
                return steps;
            }
            for(int i:arr){
                int product = (factor * i) % 100000;
                if(distance[product] > steps + 1){
                    distance[product] = steps + 1;
                    q.push({product,steps+1});
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
