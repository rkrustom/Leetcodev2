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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> result;
    vector<int> path;
    function<void(TreeNode*, int, vector<int>&, vector<vector<int>>&)> dfs = 
    [&](TreeNode* node, int remainingSum, vector<int>& currentPath, vector<vector<int>>& allPaths) {
        if (!node) return;
        currentPath.push_back(node->val);
        remainingSum -= node->val;
        if (!node->left && !node->right && remainingSum == 0) {
            allPaths.push_back(currentPath);
        } else {
            if (node->left) dfs(node->left, remainingSum, currentPath, allPaths);
            if (node->right) dfs(node->right, remainingSum, currentPath, allPaths);
        }
        currentPath.pop_back();
    };
    
    dfs(root, targetSum, path, result);
    return result;  
    }
};