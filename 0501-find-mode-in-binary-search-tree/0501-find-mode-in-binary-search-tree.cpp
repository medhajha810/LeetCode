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
    vector<int> result;
    int maxCount = 0;
    int currCount = 0;
    int prevVal;
    bool firstNode = true;

    void inorder(TreeNode* root) {
        if (!root) return;

        inorder(root->left);

        if (firstNode) {
            // For the first node, initialize
            currCount = 1;
            prevVal = root->val;
            firstNode = false;
        } else {
            if (root->val == prevVal) {
                currCount++;
            } else {
                currCount = 1;
                prevVal = root->val;
            }
        }

        if (currCount > maxCount) {
            maxCount = currCount;
            result.clear();
            result.push_back(root->val);
        } else if (currCount == maxCount) {
            result.push_back(root->val);
        }

        inorder(root->right);
    }

    vector<int> findMode(TreeNode* root) {
        inorder(root);
        return result;
    }
};
