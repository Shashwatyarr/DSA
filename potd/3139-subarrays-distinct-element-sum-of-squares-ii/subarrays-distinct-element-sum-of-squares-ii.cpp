class Solution {
public:
    int mod=1e9+7;
    int n;
    vector<long long> sqs;//sqsum
    vector<long long> s;//sum
    vector<long long> lt; //lazypropagation

    void la(int i,int l,int r,int val){
        int len=(r-l+1);
        sqs[i]+=2*val*s[i]+len*val*val;
        s[i]+=len*val;
    }

    void update(int l,int r,int i,int li,int ri,int val){
        if(lt[i]!=0){
            la(i,li,ri,lt[i]);//lazyaddition
            if(li!=ri){
                lt[2*i+1]+=lt[i];
                lt[2*i+2]+=lt[i];
            }
            lt[i]=0;
        }
        if(li>r || ri<l || li>ri){
            return;
        }
        if(li>=l && ri<=r){
            la(i,li,ri,val);
            if(li!=ri){
                lt[2*i+1]+=val;
                lt[2*i+2]+=val;
            }
            return;
        }
        int mid=li+(ri-li)/2;
        update(l,r,2*i+1,li,mid,val);
        update(l,r,2*i+2,mid+1,ri,val);
        s[i]=s[2*i+1]+s[2*i+2];
        sqs[i]=sqs[2*i+1]+sqs[2*i+2];
    }

    int sumCounts(vector<int>& nums) {
        n=nums.size();
        sqs.assign(4*n,0); 
        s.assign(4*n,0); 
        lt.assign(4*n,0); 

        vector<int> prev(100001,-1);
        long long ans=0;

        for(int i=0;i<n;i++){
            int l=prev[nums[i]]+1;
            int r=i;
            update(l,r,0,0,n-1,1);//l,r,node,rangeini,rangeend,+1
            ans= (ans+sqs[0])%mod;
            prev[nums[i]]=i;
        }
        return ans;
    }
};