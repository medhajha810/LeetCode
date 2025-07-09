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
    void helper(TreeNode* root,string number, string& result){
        if(root==NULL){
            return;
        }
        number = char('a' + root->val) + number;

        if (root->left == NULL && root->right == NULL) {
            if (result == "" || number<result) {
                result=number;
            }
            return;
        }
        helper(root->left,number,result);
        helper(root->right,number,result);
    }
public:
    string smallestFromLeaf(TreeNode* root) {
        string number="";
        string result="";
        helper(root,number,result);
        return result;

        
    }
};