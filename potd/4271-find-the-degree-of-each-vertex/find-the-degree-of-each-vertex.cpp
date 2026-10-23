class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& matrix) {
        vector<int> a;
        for(int i=0;i<matrix.size();i++){
            int sum=0;
            for(int j=0;j<matrix[i].size();j++){
                sum+=matrix[i][j];
            }
            a.push_back(sum);
        }
        return a;
    }
};