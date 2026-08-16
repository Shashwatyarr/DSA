class Solution {
public:
    int find(long long k) {
        int a = 0;
        while (k) {
            k /= 10;
            a++;
        }
        return a;
    }

    int kthDigit(long long k) {
        if (k <= 9)
            return k;

        k -= 9;

        int j = 2;
        long long start = 10;

        while (true) {
            long long blocks = 9 * (start / 10);
            long long digits = blocks * 10LL * j;

            if (k > digits) {
                k -= digits;
                start *= 10;
                j++;
            }
            else {
                break;
            }
        }

        k--;

        long long num = start + k / j;
        int rem = k % j;

        long long b = num / 10;

        if (b % 2 == 1)
            num = 10 * b + (9 - num % 10);

        string s = to_string(num);

        return s[rem] - '0';
    }
};