class Solution {
public:
    long long appealSum(string s) {
        vector<vector<int>> mpp(26);
        int n=s.size();
        for(int i=0;i<n;i++){
            mpp[s[i]-'a'].push_back(i);
        }
        long long ans=0;
        for(int i=0;i<mpp.size();i++){
            for(int j=0;j<mpp[i].size();j++){
                int prev=-1;
                if(j>0) prev=mpp[i][j-1];
                ans+=1LL*(n-mpp[i][j])*(mpp[i][j]-prev);
            }
        }
        return ans;
    }
};