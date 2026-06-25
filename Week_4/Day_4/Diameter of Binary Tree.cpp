class Solution {
public:
    int ans = 0; // stores the max diameter

    int height(TreeNode* root) {
        if (root == NULL)
            return 0;

        int leftheight = height(root->left);
        int rightheight = height(root->right);

        // diameter passing through this node = left height + right height
        ans = max(ans, leftheight + rightheight);

        // return height of this node
        return max(leftheight, rightheight) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        height(root); // this call updates ans for all nodes
        return ans;
    }
};
 