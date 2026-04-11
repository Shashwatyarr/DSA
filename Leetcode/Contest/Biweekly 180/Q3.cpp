class Solution {
public:
    void sieve(int n,vector<bool>& a){
        vector<bool> p(n+1,1);
        for(int i=2;i*i<=n;i++){
            if(p[i]==true){
                for(int j=i*i;j<=n;j+=i){
                    p[j]=0;
                }
            }
        }
        for(int i=0;i<p.size();i++){
            a.push_back(p[i]);
        }
    }
    int minOperations(vector<int>& nums) {
        vector<bool> a;
        sieve(2e5,a);
        a[1]=0;
        int count=0;
        for(int i=0;i<nums.size();i++){
            if(i%2==0 && a[nums[i]]==0){
                int j=nums[i];
                while(j<a.size() && a[j++]!=1) count++;
            } 
            else if(i%2==1 && a[nums[i]]==1){
                int j=nums[i];
                while(j<a.size() && a[j++]!=0) count++;
            }
            cout<<count<<" ";
        }
        return count;
    }
};