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
    int fhl(TreeNode* root){
        int hieght=0;
        while(root){
            hieght++;
            root=root->left;
        }
        return hieght;
    }
    
    int fhr(TreeNode* root){
         int hieght=0;
        while(root){
            hieght++;
            root=root->right;
        }
        return hieght;
    }
    int countNodes(TreeNode* root) {
        if(root==NULL) return 0;
        int lh=fhl(root);
        int rh=fhr(root);
        if(lh==rh) return (1<<lh)-1;
        return 1+countNodes(root->left)+countNodes(root->right);
    }
};