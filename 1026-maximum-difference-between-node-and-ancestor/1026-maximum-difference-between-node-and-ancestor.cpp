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
    
    int dfs(TreeNode* node,int mini,int maxi)
    {
        if(node==NULL)
        {
            return abs(maxi-mini);
        }
        int ans=INT_MIN;
        int leftsubtree=dfs(node->left,min(mini,node->val),max(maxi,node->val));
        int rightsubtree=dfs(node->right,min(mini,node->val),max(maxi,node->val));
        return max(leftsubtree,rightsubtree);
    }
    int maxAncestorDiff(TreeNode* root) {
        int mini=INT_MAX;
        int maxi=INT_MIN;
        return dfs(root,mini,maxi);
        
        
        
    }
};