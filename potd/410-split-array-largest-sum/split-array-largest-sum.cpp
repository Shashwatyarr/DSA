class Solution {
public:
    int check(vector<int>& nums,int mid){
        int k=0,sum=0;
        for(int i=0;i<nums.size();i++){
            if(sum+nums[i]<=mid) sum+=nums[i];
            else k++,sum=nums[i];
        }
        k++;
        return k;
    }
    int splitArray(vector<int>& nums, int k) {
        int maxi=INT_MIN, sum=0;
        for (auto it : nums) {
            maxi=max(maxi, it);
            sum+=it;
        }
        int l=maxi,r=sum,ans=0;
        while (l<=r) {
            int mid=l + (r - l) / 2;
            int cnt=check(nums, mid);
            if (cnt > k) {
                l=mid+1;
            } 
            else {
                r=mid-1;
                ans=mid;
            }
        }
        return ans;
    }
};