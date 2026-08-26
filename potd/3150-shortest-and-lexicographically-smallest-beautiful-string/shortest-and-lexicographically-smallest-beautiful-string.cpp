class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        int cnt = 0;
        int l = 0, r = 0;
        string ans = "";
        while (r < n) {
            if (s[r] == '1')
                cnt++;
            while (cnt > k || s[l] == '0') {
                if (s[l] == '1')
                    cnt--;
                l++;
            }
            if (cnt == k) {
                string curr = s.substr(l, r - l + 1);
                if (ans == "" || curr.size() < ans.size() ||
                    curr.size() == ans.size() && curr < ans) {
                    ans = curr;
                }
            }
            r++;
        }
        return ans;
    }
};
