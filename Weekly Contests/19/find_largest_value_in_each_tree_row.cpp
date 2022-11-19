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
    void traverseTree(TreeNode* node, vector<int> &res, int level) {

        if(node) {
            if(level == res.size())
                res.push_back(INT_MIN);

            res[level] = max(res[level], node->val);
            traverseTree(node->left, res, level + 1);
            traverseTree(node->right, res, level + 1);
        }
    }

    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        traverseTree(root, res, 0);
        return res;
    }
};
