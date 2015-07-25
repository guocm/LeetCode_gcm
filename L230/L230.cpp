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
    int kthSmallest(TreeNode* root, int k) {
        int num = 0;
        int result = 0;
        visit(root, k, num, result);

        return result;
    }
    
private:
    void visit(TreeNode *root, int k, int &num, int &result)
    {
        if (root == NULL)
        {
            return;
        }

        visit(root->left, k, num, result);
        if (num < k)
        {
            num += 1;
            if (num == k)
            {
                result = root->val;
                return;
            }
        }
        visit(root->right, k, num, result);
    }
};