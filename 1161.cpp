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
    int maxLevelSum(TreeNode* root) 
    {
        int maxsum=INT_MIN,levelctr=1,ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int ls=0,n=q.size();
            for(int i=0;i<n;i++)
            {
                TreeNode* node=q.front();
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                ls+=node->val;
            }
            if(ls>maxsum)
            {
                maxsum=max(maxsum,ls);
                ans=levelctr;
            }
            levelctr++;
        }
        return ans;
    }
};
