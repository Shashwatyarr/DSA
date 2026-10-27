class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> ans(m,"");
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==m-1){
                    ans[i]+=".";
                }
                else if(j==0) ans[i]+=".";
                else ans[i]+="#";
            }
        }
        return ans;
    }
};