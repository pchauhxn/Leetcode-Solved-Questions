class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        unordered_map<int,int> mp;
        vector<vector<int>> ans;
        for(auto i:nums1){
            mp[i[0]]+=i[1];
        }
        for(auto i:nums2){
            mp[i[0]]+=i[1];
        }
        for(auto i:mp){
            vector<int> v;
            v.push_back(i.first);
            v.push_back(i.second);
            ans.push_back(v);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};