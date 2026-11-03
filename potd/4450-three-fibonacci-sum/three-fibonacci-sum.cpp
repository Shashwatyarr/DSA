class Solution {
public:
    bool threeFibonacciSum(int n) {
        int a=0,b=1,c=1;
        while(a+b+c<n){
            a=b;
            b=c;
            c=a+b;
        }
        return a+b+c==n;
    }
};