class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        int rem=sum%9;
        int m=sum/9;
        string s;
        while(m--){
            s+='9';
        }
        if(rem!=0)
        s+='0'+rem;
        while(num>s.size()) s+='0';
        if(s.size()>num) return "";
        return s;
    }
};