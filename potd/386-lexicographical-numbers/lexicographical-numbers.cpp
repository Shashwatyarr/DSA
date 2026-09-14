class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        vector<string> c;
        for(int i=1;i<=n;i++){
            c.push_back(to_string(i));
        }
        sort(c.begin(),c.end());
        for(int i=0;i<c.size();i++){
            ans.push_back(stoi(c[i]));
        }
        return ans;
    }
};