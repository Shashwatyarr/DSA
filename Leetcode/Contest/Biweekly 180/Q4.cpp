class Solution {
public:
    static bool comp(pair<int,int>& a,pair<int,int>& b){
        if(a.first==b.first){
            return a.second<b.second;
        }
        return a.first>b.first;
    }
    int maxValue(vector<int>& nums1, vector<int>& nums0) {
        vector<pair<int,int>> a;
        for(int i=0;i<nums1.size();i++){
            a.push_back({nums1[i],nums0[i]});
        }
        sort(a.begin(),a.end(),comp);
        long long mod=1e9+7;
        long long ans=0;
        int k=0;
        for(auto& it:a){
            if(it.second>0) continue;
            for(int i=0;i<it.first;i++){
                ans=(ans*2+1)%mod;
            }
            
            for(int i=0;i<it.second;i++){
                ans=(ans*2)%mod;
            }
        }
        for(auto& it:a){
            if(it.second==0) continue;
            for(int i=0;i<it.first;i++){
                ans=(ans*2+1)%mod;
            }
            for(int i=0;i<it.second;i++){
                ans=(ans*2)%mod;
            }
        }
        return (int)ans;
    }
};