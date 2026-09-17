/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==nullptr)  return {};
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            //TreeNode* it=q.front();
            int n=q.size();
            vector<int> row(n);
            for(int i=0;i<n;i++){
                TreeNode* it=q.front();
                row[i]=it->val;
                if(it->left){
                    q.push(it->left);
                }
                if(it->right){
                    q.push(it->right);
                }
                q.pop();
            }
            ans.push_back(row);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};