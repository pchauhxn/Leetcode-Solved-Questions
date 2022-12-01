//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    
    int longestCommonSubstr (string text1, string text2, int n, int m){
        int ind1=0,ind2=0;
        vector<vector<int>> dp(n+1,(vector<int>(m+1,0)));
        for(int ind1=0;ind1<=n;ind1++) dp[ind1][0]=0;
        for(int ind2=0;ind2<=m;ind2++) dp[0][ind2]=0;
        int ans=0;
        for(ind1=1;ind1<=n;ind1++){
            for(ind2=1;ind2<=m;ind2++){
                if(text1[ind1-1]==text2[ind2-1]){
                    dp[ind1][ind2]=1+dp[ind1-1][ind2-1];
                    ans=max(ans,dp[ind1][ind2]);
                }
                else
                    dp[ind1][ind2]=0;
            }
        }
        return ans;
    }
    

};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends