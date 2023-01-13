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
    void traverseTreeDesc(TreeNode* root, int& currentSum) {
        if(!root) return;
        traverseTreeDesc(root->right, currentSum);
        currentSum += root->val;
        root->val = currentSum;
        traverseTreeDesc(root->left, currentSum);
    }

public:
    TreeNode* convertBST(TreeNode* root) {
        int currentSum = 0;
        traverseTreeDesc(root, currentSum);
        return root;
    }
};
