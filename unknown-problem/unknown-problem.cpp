class Solution {
public:
    int minNumber(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        unordered_map<int,int> mp;
        int ans=INT_MAX;
        for(auto i:nums1)
                mp[i]++;
        for(auto i:nums2){
            if(mp[i]>0)
                ans=min(ans,i);
        }
        int a=nums1[0],b=nums2[0];
        if(a<b)
            ans=min(ans,a*10+b);
        else
            ans=min(ans,b*10+a);
        return ans;
    }
};