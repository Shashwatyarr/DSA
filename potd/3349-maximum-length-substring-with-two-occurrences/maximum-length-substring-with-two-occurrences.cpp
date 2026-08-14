class Solution {
public:
    int maximumLengthSubstring(string s) {
        int maxi=0;
        for(int i=0;i<s.size();i++){
            unordered_map<int,int> mpp;
            for(int j=i;j<s.size();j++){
                mpp[s[j]]++;
                bool f=1;
                for(auto it:mpp){
                    if(it.second>2) f=0;
                }
                if(f){
                    maxi=max(maxi,j-i+1);
                }
            }    
        }
        return maxi;
    }
};