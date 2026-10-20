class Solution {
public:

    bool f(vector<int>& nums, int k) {
    int n=nums.size(),prev=INT_MIN;
    for(int i=0;i<n;i+=k) {
        int cnt=0;
        int mini=nums[i], maxi=nums[i];
        for(int j=i;j<i+k;j++) {
            mini = min(mini,nums[j]);
            maxi = max(maxi,nums[j]);
            if(j>i && nums[j-1]>nums[j]) {
                cnt++;
            }
        }
        if(nums[i+k-1]>nums[i]) cnt++;
        if(cnt>1 || prev>mini) return false;
        prev = maxi;
    }
    return true;
}

    int sortableIntegers(vector<int>& nums) {
        int n=nums.size(),ans=0;
        for(int k=1;k*k<=n;k++){
            if(n%k==0){
            if(f(nums,k)) ans+=k;
            if(k!=n/k && f(nums,n/k)) ans+=n/k;
            }
        }
        return ans;
    }
};