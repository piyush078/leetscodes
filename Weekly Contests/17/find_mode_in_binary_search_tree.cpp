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
    void inorderTraversal(TreeNode* node, vector<int>& result, int& curValue, int& curFreq, int& maxFreq) {

        if(!node) return;
        inorderTraversal(node->left, result, curValue, curFreq, maxFreq);

        if(node->val != curValue) curFreq = 1, curValue = node->val;
        else curFreq++;

        if(curFreq >= maxFreq) {
            if(curFreq > maxFreq) result.clear();
            result.push_back(node->val);
            maxFreq = curFreq;
        }

        inorderTraversal(node->right, result, curValue, curFreq, maxFreq);
    }

public:
    vector<int> findMode(TreeNode* root) {
        int curFreq = 0, maxFreq = 0, curValue = INT_MIN;
        vector<int> result;
        inorderTraversal(root, result, curValue, curFreq, maxFreq);
        return result;
    }
};
