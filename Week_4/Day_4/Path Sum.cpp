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

    bool helper(TreeNode* root, int targetSum, int sum)
    {
        if (!root) return false;

        sum += root->val;  // add current node value

        // if leaf node → check sum
        if (!root->left && !root->right)
            return sum == targetSum;

        // return true if either subtree gives true
        return helper(root->left, targetSum, sum) ||
               helper(root->right, targetSum, sum);
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) return false;
        return helper(root, targetSum, 0);
    }
};