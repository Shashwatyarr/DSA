class Solution {
public:
    bool checkDivisibility(int n) {
        int sum=0;
        int prod=1;
        int a=n;
        while(n){
            int rem=n%10;
            sum+=rem;
            prod*=rem;
            n/=10;
        }
       // cout<<prod<<" "<<sum<<" "<<n<<endl;
        return a%(sum+prod)==0;
    }
};