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
    void Helper(vector<int>& result, TreeNode* root){
        if (root==NULL){
            return;
        }
        Helper(result, root->left);
        result.push_back(root->val);
        Helper(result, root->right);

    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        Helper(result,root);
        return result;
        

        
    }
};