class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> a1 = {nums[0]};
        vector<int> a2 = {nums[1]};

        for (int i = 2; i < nums.size(); i++) {
            if (a1.back() > a2.back())
                a1.push_back(nums[i]);
            else
                a2.push_back(nums[i]);
        }

        a1.insert(a1.end(), a2.begin(), a2.end());
        return a1;
    }
};