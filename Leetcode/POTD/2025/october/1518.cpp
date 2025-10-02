class Solution
{
public:
    int numWaterBottles(int numBottles, int numExchange)
    {
        int sum = 0;
        sum = numBottles;
        while (true)
        {
            sum += numBottles / numExchange;
            numBottles = numBottles / numExchange + (numBottles % numExchange);
            if (numBottles / numExchange == 0)
            {
                break;
            }
        }
        return sum;
    }
};