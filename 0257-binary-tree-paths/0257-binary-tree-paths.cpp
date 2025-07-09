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
    void preOrder(TreeNode* root, string result,vector<string>& sum){
        if(root==NULL){
            return;
        } 
        if(!result.empty()){
            result+="->";
        }
        result+=to_string(root->val);
        if(root->left==NULL && root->right==NULL){
            sum.push_back(result);
        }
        preOrder(root->left, result,sum);
        preOrder(root->right, result, sum);
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> sum;
        string result;
        preOrder(root,result,sum);
        return sum;
        
    }
};