class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        mpp[0]=1;
        int sum=0;
        int count=0;
        for(auto it:nums){
            sum+=it;
            int mod=(sum%k+k)%k;
            if(mpp.find(mod)!=mpp.end())
                count+=mpp[mod];
            mpp[mod]++;
        }
        return count;
    }
};