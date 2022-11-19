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
    void lastRowLeftest(TreeNode* node, int& answer, int level, int& maxLevel) {

        if(!node) return;
        if(level > maxLevel)
            answer = node->val, maxLevel = level;

        lastRowLeftest(node->left, answer, level + 1, maxLevel);
        lastRowLeftest(node->right, answer, level + 1, maxLevel);
    }

public:
    int findBottomLeftValue(TreeNode* root) {
        int answer = 0, maxLevel = -1;
        lastRowLeftest(root, answer, 0, maxLevel);
        return answer;
    }
};
