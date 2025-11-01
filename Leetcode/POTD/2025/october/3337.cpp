class Solution {
public:
    int smallestNumber(int n) {
        int a=log2(n);
        if(!(n&n+1)) return n;
        else return pow(2,a+1)-1;
    }
};