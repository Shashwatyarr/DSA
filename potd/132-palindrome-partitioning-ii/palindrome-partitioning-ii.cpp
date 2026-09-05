class Solution {
    vector<vector<int>> dp;
    vector<vector<int>> dp1;
public:

    int solve(string &s, int i,int j){
        if(i>=j) return 1;
        if(dp1[i][j]!=-1) return dp1[i][j];
        if(s[i]==s[j]) return dp1[i][j]=solve(s,i+1,j-1);
        return dp1[i][j]=0;
    }

    void longestPalindrome(string& s) {
        int n=s.size();
        string ans="";
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                int f=solve(s,i,j);
            }
        }
    }


    int find(string& s,int i,int j){
        if(i>=s.size() && j>=s.size()) return 1;
        if(j>=s.size()) return INT_MAX;
        if(dp[i][j]!=-1) return dp[i][j];
        int take=1e8;
        if(dp1[i][j]){
            int curr=find(s,j+1,j+1);
            if(curr!=INT_MAX)
            take=1+curr;
        }
        int nottake=find(s,i,j+1);
        return dp[i][j]=min(take,nottake);
    }

    int minCut(string s) {
        int n=s.size();
        dp.resize(n,vector<int>(n,-1));
        dp1.resize(n,vector<int>(n,-1));
        for(int i=0;i<n;i++) dp1[i][i]=1;
        longestPalindrome(s);
        return find(s,0,0)-2;
    }
};