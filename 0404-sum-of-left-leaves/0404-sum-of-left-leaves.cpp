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
    void helper(int &sum,TreeNode* root){
        if(root==NULL){
            return;
        }
        if(root->left!=NULL && root->left->right==NULL && root->left->left==NULL){
            sum+=root->left->val;
        }
        helper(sum,root->left);
        helper(sum,root->right);
    }
public:
    int sumOfLeftLeaves(TreeNode* root) {
        int sum=0;
        helper(sum, root);
        return sum;
        
    }
};