class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        int a=0,d=0;
        for(int i=1;i<n;i++){
            a+=nums[i]==(nums[i-1]+1)%n;
        }    
        for(int i=1;i<n;i++){
            d+=nums[i-1]==(nums[i]+1)%n;
        }    
        if(a==n-1 && nums[0]==0) return 0;
        if(a==n-1) {
            int l=n-nums[0];
            int r=1+(nums.back()+1)+1;
            return min(l,r);
        }
        if(d==n-1){
            int l=n-nums.back()+1;
            int r=(nums[0]+1)%n+1;
            return min(l,r);
        }
        return -1;
    }
};