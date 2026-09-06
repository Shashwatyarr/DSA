class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        int n=nums.size();
        nums.insert(nums.end(),nums.begin(),nums.end());
        vector<long long> pre(2*n+1,0);
        pre[0]=nums[0];
        for(int i=1;i<2*n;i++){
            pre[i]=nums[i]+pre[i-1];
        }
        long long tsum=pre[n-1];
        int l=0,len=n/2;
        int count=0;
        while(l<n){
            int r=l+len;
            if(tsum-(pre[r]-pre[l])<(pre[r]-pre[l])) count++;
            l++;
        }
        return count;
    }
};