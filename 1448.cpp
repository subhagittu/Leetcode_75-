class Solution {
public:
    int goodNodes(TreeNode* root) {
        int good = 0;
        dfs(root, INT_MIN, good);
        return good;
    }

    void dfs(TreeNode* root, int max_val, int& good) {
        if (root == NULL) {
            return;
        }

        if (root->val >= max_val) {
            good++;
        }

        max_val = max(max_val, root->val);

        dfs(root->left, max_val, good);
        dfs(root->right, max_val, good);
    }
};
