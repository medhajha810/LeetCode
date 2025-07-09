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
    void helper(TreeNode* root, int sum, int targetSum, vector<int>& a, vector<vector<int>>& b){
        if(root==NULL){
            return;
        }
        sum+=root->val;
        a.push_back(root->val);
        if(root->left==NULL && root->right==NULL){
            if(sum==targetSum){
                b.push_back(a);
            }
            
        }
        helper(root->left,sum,targetSum,a,b);
        helper(root->right,sum,targetSum,a,b);
        a.pop_back();
    }

public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int>a;
        vector<vector<int>>b;
        int sum=0;
        helper(root,sum,targetSum,a,b);
        return b;
        
    }
};