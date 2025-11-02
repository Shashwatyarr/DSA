class Solution
{
public:
    int countUnguarded(int m, int n, vector<vector<int>> &guards, vector<vector<int>> &walls)
    {
        vector<vector<int>> ans(m, vector<int>(n, 0));
        for (int i = 0; i < guards.size(); i++)
        {
            ans[guards[i][0]][guards[i][1]] = 1;
        }
        for (int i = 0; i < walls.size(); i++)
        {
            ans[walls[i][0]][walls[i][1]] = 2;
        }
        for (int i = 0; i < guards.size(); i++)
        {
            int x = guards[i][0], y = guards[i][1];
            for (int j = x - 1; j >= 0; j--)
            {
                if (ans[j][y] == 2 || ans[j][y] == 1)
                    break;
                ans[j][y] = 3;
            }
            for (int j = x + 1; j < m; j++)
            {
                if (ans[j][y] == 2 || ans[j][y] == 1)
                    break;
                ans[j][y] = 3;
            }
            for (int j = y - 1; j >= 0; j--)
            {
                if (ans[x][j] == 2 || ans[x][j] == 1)
                    break;
                ans[x][j] = 3;
            }
            for (int j = y + 1; j < n; j++)
            {
                if (ans[x][j] == 2 || ans[x][j] == 1)
                    break;
                ans[x][j] = 3;
            }
        }
        int count = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (ans[i][j] == 0)
                    count++;
            }
        }
        return count;
    }
};