class Solution
{
public:
    int minJumps(vector<int> &arr)
    {
        map<int, vector<int>> mpp;
        int n = arr.size();
        for (int i = n - 1; i >= 0; i--)
            mpp[arr[i]].push_back(i);
        vector<int> vis(n, 1e9);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0});
        vis[0] = 0;
        while (!pq.empty())
        {
            auto [steps, idx] = pq.top();
            pq.pop();
            if (idx == n - 1)
                return steps;
            for (auto &it : mpp[arr[idx]])
            {
                if (vis[it] <= steps + 1)
                    continue;
                vis[it] = steps + 1;
                pq.push({steps + 1, it});
            }
            mpp.erase(arr[idx]);
            if (idx < n - 1 && vis[idx + 1] > steps + 1)
            {
                pq.push({steps + 1, idx + 1});
                vis[idx + 1] = steps + 1;
            }
            if (idx > 0 && vis[idx - 1] > steps + 1)
            {
                vis[idx - 1] = steps + 1;
                pq.push({steps + 1, idx - 1});
            }
        }
        return -1;
    }
};