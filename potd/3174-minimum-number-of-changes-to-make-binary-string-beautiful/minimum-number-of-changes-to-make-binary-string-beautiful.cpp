class Solution {
public:
    int minChanges(string s) {
        int n=s.size();
        int count=0;
        for(int i=1;i<n;i++){
            if(s[i]!=s[i-1]) count++;
            i++;
        }
        return count;
    }
};