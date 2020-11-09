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
    void traverse(TreeNode* root,int min,int max)
    {
        if(root==0)
            return;
        if(root->val>max)
            max=root->val;
        if(root->val<min)
            min=root->val;
        if(abs(min-max)>ans)
            ans=abs(min-max);
        traverse(root->left,min,max);
        traverse(root->right,min,max);
    }
    int maxAncestorDiff(TreeNode* root) {
        ans=0;
        traverse(root,INT_MAX,INT_MIN);
        return ans;
        
    }
};
