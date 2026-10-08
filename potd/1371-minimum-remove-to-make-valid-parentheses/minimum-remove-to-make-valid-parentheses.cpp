class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int o = 0, c = 0;
        int n = s.size();

        vector<int> a;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(')
                o++;

            else if (s[i] == ')') {
                if (o == 0) {
                    a.push_back(i);
                } else {
                    o--;
                }
            }
        }
        for (int i = n - 1; i >= 0 && o > 0; i--) {
            if (s[i] == '(') {
                a.push_back(i);
                o--;
            }
        }

        sort(a.begin(), a.end());

        string t = "";
        int j = 0;

        for (int i = 0; i < n; i++) {
            if (j < a.size() && a[j] == i) {
                j++;
            } else {
                t += s[i];
            }
        }

        return t;
    }
};