class Solution
{
public:
    int maxBottlesDrunk(int nb, int ne)
    {
        int cnt = nb;
        while (nb >= ne)
        {
            nb -= ne - 1;
            ne++;
            cnt++;
        }
        return cnt;
    }
};