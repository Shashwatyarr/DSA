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
    int count=0;
    void inos(TreeNode* root,int& sum){
        if(!root) return;
        if(root->left) inos(root->left,sum);
        sum+=root->val;
        if(root->right) inos(root->right,sum);
    }
    void inoc(TreeNode* root,int& sum){
        if(!root) return;
        if(root->left) inoc(root->left,sum);
        sum++;
        if(root->right) inoc(root->right,sum);
    }
    int sum(TreeNode* root){
        int sum=0;
        inos(root,sum);
        return sum;
    }
    int cnt(TreeNode* root){
        int count=0;
        inoc(root,count);
        return count;
    }
    bool avg(TreeNode* root){
        if(cnt(root)!=0){
        if(sum(root)/cnt(root)==root->val) return 1;
        return 0;
        }
        return 0;
    }
    void ino(TreeNode* root){
        if(!root) return;
        if(root->left) ino(root->left);
        if(avg(root)) count++;
        if(root->right) ino(root->right);
    }
    int averageOfSubtree(TreeNode* root) {
        ino(root);
        return count;
    }
};