class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            nums[i]=pow(nums[i],2);
        }
        sort(nums.begin(),nums.end(),greater<int>());
        int k=0;
        if(nums.size()%2) k=nums.size()/2+1;
        else k=nums.size()/2;
        long long sum=0;
        int i;
        for(i=0;i<k;i++){
            sum+=nums[i];
        }
        for(int j=k;j<nums.size();j++){
            sum-=nums[j];
        }
        return sum;
    }
};