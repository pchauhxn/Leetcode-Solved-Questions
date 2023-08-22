//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> longestIncreasingSubsequence(int n, vector<int>& arr) {
        // Code here
        vector<int> dp(n,1),hash(n);
        int maxi=1,lastind=0;
        for(int ind=0;ind<n;ind++){
            hash[ind]=ind;
            for(int prev=0;prev<ind;prev++){
                if(arr[ind]>arr[prev] && dp[ind]<1+dp[prev]){
                    dp[ind]=1+dp[prev];
                    hash[ind]=prev;
                }
            }
            if(maxi<dp[ind]){
                maxi=dp[ind];
                lastind=ind;
            }
        }
        vector<int> ans;
        ans.push_back(arr[lastind]);
        while(hash[lastind]!=lastind){
            lastind=hash[lastind];
            ans.push_back(arr[lastind]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        vector<int> res = obj.longestIncreasingSubsequence(N, arr);
        for (auto x : res) cout << x << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends