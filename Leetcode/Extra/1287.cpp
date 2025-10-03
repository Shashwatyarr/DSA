class Solution
{
public:
    int findSpecialInteger(vector<int> &arr)
    {
        int count = 0, a = arr[0];
        for (int i = 0; i < arr.size() - 1; i++)
        {
            if (arr[i] == arr[i + 1])
            {
                count++;
                a = arr[i];
            }
            else
            {
                if (count >= (arr.size() / 4))
                    return a;
                count = 0;
                a = -1;
            }
        }
        if (count >= (arr.size() / 4))
            return a;
        return a;
    }
};