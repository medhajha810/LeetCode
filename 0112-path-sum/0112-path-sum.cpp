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
    void helper(TreeNode* root, int sum, int targetSum, bool &a){
        if(root==NULL){
            return;
        }
        sum+=root->val;
        if(root->left==NULL && root->right==NULL){
            if(sum==targetSum){
                a=true;
                return;
            }
            
        }
        helper(root->left,sum,targetSum,a);
        helper(root->right,sum,targetSum,a);

    }
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        bool a=false;
        int sum=0;
        helper(root,sum,targetSum,a);
        return a;

        
    }
};