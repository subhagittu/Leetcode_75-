/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL)
        return NULL;

        if(root->val==p->val || root->val==q->val)
        {
            return root;
        }

        TreeNode* left = lowestCommonAncestor(root->left,p,q);
        TreeNode* right = lowestCommonAncestor(root->right,p,q);
        if(left==NULL && right==NULL)
        return NULL;
        else{
            if(left!=NULL && right!=NULL) // if p/q is present on the left and p/q present on the right then root is the lca
            return root;
            else if(left!=NULL) // if p/q is present on the left or both p and q is present on the left 
            return left;
            else // if p/q is present on the right or both p and q is present on the right
            return right;
        }   
    }
};
