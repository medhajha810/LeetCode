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
void helper(TreeNode* root, vector<int> & result){
    if(root==NULL){
        return;
    }
    if(root->left==NULL && root->right!=NULL){
        result.push_back(-1);
    }
    result.push_back(root->val);
    helper(root->left,result);
    helper(root->right, result);
}
    
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<int> r1;
        vector<int> r2;
        helper(p,r1);
        helper(q,r2);
        return r1==r2;
    }
};