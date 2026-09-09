class Solution {
public:
    int uniqueLetterString(string s) {
        vector<vector<int>> mpp(26);
        int n=s.size();
        for(int i=0;i<n;i++){
            mpp[s[i]-'A'].push_back(i);
        }
        int ans=0;
        for(int i=0;i<mpp.size();i++){
            for(int j=0;j<mpp[i].size();j++){
                int prev=-1, next=n;

                if(j>0) prev=mpp[i][j-1];
                if(j<mpp[i].size()-1) next=mpp[i][j+1];

                ans+=(next-mpp[i][j])*(mpp[i][j]-prev);
            }
        }
        return ans;
    }
};