class Solution {
public:
    int minSwaps(vector<int>& nums) {
        vector<pair<pair<int, int>, int>> ans(nums.size());
        for (int i = 0; i < nums.size(); ++i) {
            int sum = 0;
            int temp = nums[i];
            while (temp > 0) {
                sum += temp % 10;
                temp /= 10;
            }
            ans[i] = {{sum, nums[i]}, i};
        }
        sort(ans.begin(), ans.end(), [](const pair<pair<int, int>, int>& a, const pair<pair<int, int>, int>& b) {
            if (a.first.first != b.first.first) {
                return a.first.first < b.first.first;
            }
            return a.first.second < b.first.second;
        });

        vector<int> trk(nums.size());
        map<int, int> mpp;
        for (int i = 0; i < nums.size(); ++i) {
            trk[i] = ans[i].first.second;
            mpp[trk[i]] = i;
        }

        vector<bool> visited(nums.size(), false);
        int swaps = 0;

        for (int i = 0; i < nums.size(); ++i) {
            if (!visited[i]) {
                int a = 0;
                int b=i;
                while (!visited[b]) {
                    visited[b] = 1;
                    b = mpp[nums[b]];
                    a++;
                }
                if (a > 0) {
                    swaps += a - 1;
                }
            }
        }
        return swaps;
    }
};