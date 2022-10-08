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
    void swapOddLevels(TreeNode* node_A, TreeNode* node_B, int level) {
        if(node_A == NULL)
            return;
        
        if(level % 2 == 0)
            swap(node_A->val, node_B->val);
        
        swapOddLevels(node_A->left, node_B->right, level + 1);
        swapOddLevels(node_A->right, node_B->left, level + 1);
    }
    
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        swapOddLevels(root->left, root->right, 0);
        return root;
    }
};
