class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        vector<int> a(nums.begin(),nums.end());
        sort(a.begin(),a.end());
        vector<int> b;
        for(int i=0;i<nums.size();i++){
            if(a[i]!=nums[i]) b.push_back(nums[i]);
        }
        if(!b.size()) return 0;
        int ans=b[0];
        for(int i=0;i<b.size();i++){
            ans&=b[i];
        }
        return ans;
    }
};