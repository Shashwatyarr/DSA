class Solution {
public:
    vector<int> maxDepthAfterSplit(string s) {
        vector<int> a;
        int d = 0;
        for (char c : s) {
            if (c == '(') {
                a.push_back(d % 2);
                d++;
            } else {
                d--;
                a.push_back(d % 2);
            }
        }
        return a;
    }
};