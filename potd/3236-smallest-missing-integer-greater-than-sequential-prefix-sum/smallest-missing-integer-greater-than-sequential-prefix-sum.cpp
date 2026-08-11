class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n=nums.size();
        int sum=nums[0];
        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1]+1){
                sum+=nums[i];
            }
            else break;
        }
        set<int>st;
        for(auto it:nums) st.insert(it);
        while(st.count(sum)){
            sum++;
        }
        return sum;
    }
};