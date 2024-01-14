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
    int ans;
    struct prop
    {
        bool bst;
        int maxsum;
        int maxi;
        int mini;
        prop()
        {
            bst=true;
            maxi=INT_MIN;
            mini=INT_MAX;
            maxsum=0;
        }
    };
    prop calculate(TreeNode* node)
    {
        if(node==NULL)
        {
            return prop();
        }
        prop p;
        prop pleft=calculate(node->left);
        prop pright=calculate(node->right);
        if(pleft.bst==true && pright.bst==true && pleft.maxi<node->val && pright.mini>node->val)
        {
            p.bst=true;
            p.maxsum=pleft.maxsum+pright.maxsum+node->val;
            p.maxi=max(node->val,pright.maxi);
            p.mini=min(node->val,pleft.mini);
            
        }
        
        else
        {
            p.bst=false;
            p.maxsum=max(pleft.maxsum,pright.maxsum);
            
        }
        ans=max(ans,p.maxsum);
        return p;
    }
    int maxSumBST(TreeNode* root) {
        ans=0;
        calculate(root);
        return ans;
        
    }
};