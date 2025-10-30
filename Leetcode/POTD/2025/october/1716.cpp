class Solution
{
public:
    int totalMoney(int n)
    {
        int a = n / 7;
        int b = n % 7;
        int sum = a * 28 + (7) * (a * (a - 1) / 2);
        for (int i = 1; i <= b; i++)
        {
            sum += a + i;
        }
        return sum;
    }
};