class Solution {
public:
    vector<vector<int>> dp;

    int find(string& s, string& t,int i,int j){
        //if(i==t.size()) return 1;
        if(i>=t.size()) return 1; 
        if(j>=s.size()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int take=0;
        if(t[i]==s[j]){
            take=find(s,t,i+1,j+1);
        }
        int nottake=find(s,t,i,j+1);
        return dp[i][j]=take+nottake;
    }

    int numDistinct(string s, string t) {
        int n=s.size(),m=t.size();
        dp.resize(m,vector<int>(n,-1));
        return find(s,t,0,0);
    }
};