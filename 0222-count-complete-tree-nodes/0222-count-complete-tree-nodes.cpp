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
    // Helper function to find height of leftmost path
    int findHeightLeft(TreeNode* node) {
        int height = 0;
        while (node) {
            height++;
            node = node->left;
        }
        return height;
    }

    // Helper function to find height of rightmost path
    int findHeightRight(TreeNode* node) {
        int height = 0;
        while (node) {
            height++;
            node = node->right;
        }
        return height;
    }

    int findHeight(TreeNode* node, bool isLeft){
        int height = 0;
        while(node){
            height++;
            node = isLeft ? node->left : node->right;
        }
        return height;
    }
    int countNodes(TreeNode* root) {
        if(root == nullptr)
            return 0;
            int lh = findHeight(root, true);
            int rh = findHeight(root, false);

            if(lh == rh)
                return (1 << lh) - 1; // (2^ h) - 1
            
            return 1 + countNodes(root->left) + countNodes(root->right);
    }
};