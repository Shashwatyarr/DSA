class Solution {
public:
    vector<int> dp;

    bool f(string& s,vector<string>& dict,int idx){
        if(idx>=s.size()) return 1;
        if(dp[idx]!=-1) return dp[idx];
        string t="";
        for(int j=idx;j<s.size();j++){
            t+=s[j];
            if(std::find(dict.begin(),dict.end(),t)!=dict.end() && f(s,dict,j+1)){
                return dp[idx]=1;
            }
        }
        return dp[idx]=0;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.size();
        dp.resize(n,-1);
        return f(s,wordDict,0);
    }
};