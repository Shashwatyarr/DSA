class Solution {
public:
    vector<vector<int>> dp;
    int find(string& s,string& t,int i,int j){
        if(i<0) return j+1;
        if(j<0) return i+1;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==t[j]) return dp[i][j]=find(s,t,i-1,j-1);
        int a=find(s,t,i,j-1);
        int b=find(s,t,i-1,j);
        int c=find(s,t,i-1,j-1);
        return dp[i][j]=1+min({a,b,c});
    }

    int minDistance(string s, string t) {
        int n=s.size(),m=t.size();
        dp.resize(n+1,vector<int>(m+1,-1));
        return find(s,t,n-1,m-1);
    }
};