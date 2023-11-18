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
    void solve(TreeNode* root,int targetSum,int &path, vector<int> &add)
    {
        if(root==NULL)
        return;

        add.push_back(root->val);

        solve(root->left,targetSum,path,add);
        solve(root->right,targetSum,path,add);

        long long sum = 0;

        for(int i = add.size()-1; i>=0; i--)
        {
            sum += add[i];

            if(sum==targetSum)
            {
                path++;
            }
        }
        add.pop_back();
    }
    int pathSum(TreeNode* root, int targetSum) {

        int path = 0;
        vector<int> add;
        solve(root,targetSum,path,add);
        return path;
        
    }
};
