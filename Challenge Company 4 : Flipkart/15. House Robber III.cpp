/*
https://leetcode.com/problems/house-robber-iii/
*/

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
    pair<int,int> solve(TreeNode* root){    
        if(!root) return {0,0};
        auto left = solve(root->left);
        auto right = solve(root->right);

        int robRoot = root->val + left.second + right.second;
        int dontRobRoot = max(left.first, left.second) +max(right.first, right.second) ;
        // cout<<root->val<<" "<<robRoot<<" "<<dontRobRoot<<endl;
        return {robRoot, dontRobRoot};
    }

    int rob(TreeNode* root) {
        auto p = solve(root);
        return max(p.first, p.second);
    }
};
