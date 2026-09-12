class Solution {
public:
    static bool comp(vector<int>& a, vector<int>& b) {
        if (a[0] == b[0])
            return a[1] > b[1];
        return a[0] < b[0];
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), comp);
        vector<int> temp;
        for (int i = 0; i < envelopes.size(); i++) {
            int h = envelopes[i][1];
            int idx = lower_bound(temp.begin(), temp.end(), h) - temp.begin();
            if (idx == temp.size())
                temp.push_back(h);
            else
                temp[idx] = h;
        }
        return temp.size();
    }
};