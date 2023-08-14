//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    vector<int> toposort(vector<int> adj[],int K){
        vector<int> topo;
        queue<int> q;
        vector<int> indeg(K,0);
        for(int i=0;i<K;i++){
            for(auto j:adj[i]){
                indeg[j]++;
            }
        }
        for(int i=0;i<indeg.size();i++){
            if(indeg[i]==0)
                q.push(i);
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            topo.push_back(node);
            for(auto i:adj[node]){
                indeg[i]--;
                if(indeg[i]==0)
                    q.push(i);
            }
        }
        return topo;
    }
    string findOrder(string dict[], int N, int K) {
        //code here
        vector<int> adj[K];
        for(int i=0;i<N-1;i++){
            string a=dict[i];
            string b=dict[i+1];
            int x=0;
            while(x<min(dict[i].length(),dict[i+1].length())){
                if(dict[i][x]!=dict[i+1][x]){
                    adj[dict[i][x]-'a'].push_back(dict[i+1][x]-'a');
                    break;
                }
                x++;
            }
        }
        vector<int> topo=toposort(adj,K);
        string ans="";
        for(int i=0;i<topo.size();i++){
            ans+=topo[i]+'a';
        }
        return ans;
    }
};

//{ Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends