class Solution
{
public:
    string fractionToDecimal(int n, int d)
    {
        if (n == 0)
            return "0";

        string s;
        if ((n < 0) ^ (d < 0))
            s += "-";
        long long num = llabs((long long)n);
        long long den = llabs((long long)d);
        s += to_string(num / den);
        long long rem = num % den;
        if (rem == 0)
            return s;
        s += ".";
        unordered_map<long long, int> seen;

        while (rem != 0)
        {
            if (seen.count(rem))
            {
                s.insert(seen[rem], "(");
                s += ")";
                break;
            }
            seen[rem] = s.size();
            rem *= 10;
            s += to_string(rem / den);
            rem %= den;
        }

        return s;
    }
};