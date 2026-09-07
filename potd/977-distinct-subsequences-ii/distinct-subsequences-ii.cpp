class Solution {
public:
    vector<int> dp;
    int MOD=1e9+7;
    int find(string& s,unordered_map<char,int>& mpp, int i){
        if(i==s.size()) return 1;
        if(dp[i]!=-1) return dp[i];
        long long take=find(s,mpp,i+1);
        long long sum=((take*2)-mpp[s[i]]+MOD)%MOD;
        mpp[s[i]]=take;
        return dp[i]=sum;
    }

    int distinctSubseqII(string s) {
        int n=s.size();
        dp.resize(n,-1);
        unordered_map<char,int> mpp;
        for(auto it:s){
            mpp[it]=0;
        }
        return (find(s,mpp,0)-1+MOD)%MOD;
    }
};