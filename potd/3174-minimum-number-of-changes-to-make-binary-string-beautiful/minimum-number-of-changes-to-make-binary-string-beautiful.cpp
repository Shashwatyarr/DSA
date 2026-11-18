class Solution {
public:
    int minChanges(string s) {
        int n=s.size(), count=0;
        for(int i=1;i<n;i+=2)
            if(s[i]!=s[i-1]) count++;
        return count;
    }
};