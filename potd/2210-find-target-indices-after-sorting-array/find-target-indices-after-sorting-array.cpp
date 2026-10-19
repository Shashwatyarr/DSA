class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int> a;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            if(nums[i]==target){
                a.push_back(i);
            }
        }
        return a;
    }
};