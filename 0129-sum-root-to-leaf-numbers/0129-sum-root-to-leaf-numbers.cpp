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
    void preOrder(TreeNode* root, int result,int& sum){
        if(root==NULL){
            return;
        } 
        result= result*10 + root->val;
        if(root->left==NULL && root->right==NULL){
            sum+=result;
        }
        preOrder(root->left, result,sum);
        preOrder(root->right, result, sum);
    }
public:
    int sumNumbers(TreeNode* root) {
        int result=0;
        int sum=0;
        preOrder(root,result, sum);
        return sum;
        
    }
};