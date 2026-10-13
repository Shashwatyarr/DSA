class Solution {
public:
vector<vector<int>> dp;

    bool check(string& s1,string& s2){
        if(s1.size()!=s2.size()+1) return 0;
        int l=0,r=0;
        while(l<s1.size()){
            if(s1[l]==s2[r]) {
                l++;r++;
            }
            else l++;
        }
        if(l==s1.size() && r==s2.size()) return 1;
        return 0;
    }

    int find(vector<string>& nums,int i,int j){
        if(i>=nums.size()) return 0;
        if(dp[i][j]!=1) return dp[i][j];
        int take=0, nottake=0;
        if(j==nums.size() || check(nums[i],nums[j]))
        take=1+find(nums,i+1,i);
        nottake=find(nums,i+1,j);
        return dp[i][j]=max(take,nottake);
    }

    static bool comp(string& a, string& b){
        return a.size()<b.size();
    }

    int longestStrChain(vector<string>& words) {
        int n=words.size();
        sort(words.begin(),words.end(),comp);
        dp.resize(n,vector<int>(n+1,1));
        return find(words,0,n);
    }
};
