class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int mini=min_element(nums.begin(),nums.end())-nums.begin();
        int maxi=max_element(nums.begin(),nums.end())-nums.begin();
        int dmi=min(mini,(int)nums.size()-mini);
        int dma=min(maxi,(int)nums.size()-maxi);
        return min({max(mini,maxi)+1,(int)nums.size()-min(mini,maxi),dma+dmi+1});
    }
};