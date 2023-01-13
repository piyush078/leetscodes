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
private:
    int diameter = 0;

    int calculateDiameter(TreeNode* node) {
        if(!node) return 0;
        int leftDepth = calculateDiameter(node->left);
        int rightDepth = calculateDiameter(node->right);
        diameter = max(diameter, leftDepth + rightDepth);
        return 1 + max(leftDepth, rightDepth);
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        calculateDiameter(root);
        return diameter;
    }
};
