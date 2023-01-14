/*
https://leetcode.com/problems/count-nodes-equal-to-average-of-subtree/
*/

class Solution {
public:
    int c=0;
    pair<int,int> tSum(TreeNode* root){
        if(root==NULL) return {0,0};
        
        auto leftTreeeSum = tSum(root->left);
        auto rightTreeSum = tSum(root->right);

        int n = 1 + leftTreeeSum.second + rightTreeSum.second;      // no. of nodes
        int sum = root->val+ leftTreeeSum.first+ rightTreeSum.first;  // sum
        c += (root->val == sum/n);              // avg count
        
        return {sum, n};
    }
    
    int averageOfSubtree(TreeNode* root) {
        tSum(root);
        return c;
    }
};
