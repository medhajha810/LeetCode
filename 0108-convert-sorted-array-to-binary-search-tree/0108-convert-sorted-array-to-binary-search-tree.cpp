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
    TreeNode* sort(vector<int>& nums, int min, int  max){
        if(min>max) return NULL;
        int mid=(min+max)/2;
        TreeNode* root=new TreeNode(nums[mid]);
        root->left= sort(nums, min, mid-1);
        root->right = sort(nums,mid+1, max);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int min=0;
        int max=nums.size()-1;
        return sort(nums, min, max);
        
        
    }
};