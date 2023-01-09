/*
https://leetcode.com/problems/all-elements-in-two-binary-search-trees/
*/

class Solution {
public:   
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        stack <TreeNode*> s1, s2; 
        vector<int> ans;
    
        while (root1 || root2 || !s1.empty() || !s2.empty())
        {
            while(root1){
                s1.push(root1);
                root1 = root1->left;
            }
            while(root2){
                s2.push(root2);
                root2 = root2->left;
            }   
            if(s2.empty() || (!s1.empty() && s1.top()->val <= s2.top()->val)){
                root1 = s1.top();
                s1.pop();
                ans.push_back(root1->val);
                root1 = root1->right;

            }else{
                root2 = s2.top();
                s2.pop();
                ans.push_back(root2->val);
                root2 = root2->right;
            }      
        }
        return ans;
    }
};
