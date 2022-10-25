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
    unordered_map<int, int> sums;
    unordered_map<int, int>::iterator it;
    
public:
    int pathSum(TreeNode* root, int targetSum) {
        sums[0] = 1;
        return traversal(root, targetSum, 0);
    }
    
    int traversal(TreeNode* root, int target, int sum) {
        if(!root) return 0;
        
        sum += root->val;
        it = sums.find(sum - target);
        int count = it == sums.end() ? 0 : it->second;
        sums[sum] = (sums.find(sum) == sums.end() ? 0 : sums[sum]) + 1;
        
        count += traversal(root->left, target, sum)
            + traversal(root->right, target, sum);
        sums[sum]--;
        
        return count;
    }
};
