class Solution {
public:
    static bool comp(const pair<int, int>& a, const pair<int, int>& b) {
        return a.second < b.second;
    }

    vector<string> maxNumOfSubstrings(string s) {
        int n = s.size();
        vector<pair<int, int>> mpp(26, {-1, -1});
        for (int i = 0; i < n; i++) {
            if (mpp[s[i] - 'a'].first == -1)
                mpp[s[i] - 'a'].first = i;
        }
        for (int i = n - 1; i >= 0; i--) {
            if (mpp[s[i] - 'a'].second == -1)
                mpp[s[i] - 'a'].second = i;
        }
        vector<pair<int, int>> arr;
        for (auto it : mpp) {
            if (it.first != -1) {
                arr.push_back({it.first, it.second});
            }
        }
        vector<pair<int,int>> a;

        for (int i = 0; i < arr.size(); i++) {
            bool f = 0;
            int l = arr[i].first;
            int r = arr[i].second;
            //string t;
            for (int j = l; j <= r; j++) {
                if (mpp[s[j] - 'a'].first < l) {
                    f = 1;
                    break;
                }
                r = max(r, mpp[s[j] - 'a'].second);
            }
            if (f == 0 ) {
                a.push_back({l,r});
            }
        }

        sort(a.begin(), a.end(), comp);
        // vector<bool> vis(n, 0);
        int prev = -1;
        vector<string> ans;
        for (int i = 0; i < a.size(); i++) {
            bool f = 0;
            int l = a[i].first;
            int r = a[i].second;
            if (l > prev) {
                ans.push_back(s.substr(l, r - l + 1));
                prev = r;
            }
        }
        return ans;
    }
};