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
    int traverseTree(TreeNode* node, unordered_map<int, int>& freqOfSum, int& maxCount) {

        if(!node) return 0;
        int sum = traverseTree(node->left, freqOfSum, maxCount) +
            traverseTree(node->right, freqOfSum, maxCount) + node->val;

        maxCount = max(maxCount, ++freqOfSum[sum]);
        return sum;
    }

public:
    vector<int> findFrequentTreeSum(TreeNode* root) {

        int maxCount = 0;
        unordered_map<int, int> freqOfSum;
        vector<int> result;

        traverseTree(root, freqOfSum, maxCount);
        for(auto& it: freqOfSum) {
            if(it.second == maxCount) result.push_back(it.first);
        }

        return result;
    }
};
