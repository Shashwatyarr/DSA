class Solution {
public:
    bool checkString(string s) {
        for(int i=0;i<s.size();i++){
            if(s[i]=='b'){
                for(int j=i;j<s.size();j++){
                    if(s[j]=='a'){
                        return 0;
                    }
                }
            }
        }
        return 1;
    }
};