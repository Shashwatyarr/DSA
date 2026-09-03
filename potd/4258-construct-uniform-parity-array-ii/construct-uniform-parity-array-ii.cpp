class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        vector<int> a;
        int k=*min_element(nums1.begin(),nums1.end());
        int f=0;
        for(auto it:nums1){
            if(it%2!=0){
                f=1;
            }
        }
        if(k%2!=0){
            return 1;
        }
        return !f;
    }
};