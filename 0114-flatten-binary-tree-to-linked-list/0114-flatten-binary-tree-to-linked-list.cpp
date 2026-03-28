/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
private:
    void flattenOptmal(TreeNode* root) {
        // Initialize a pointer
        // 'curr' to the root of the tree
        TreeNode* curr = root;

        // Iterate until 'curr'
        // becomes NULL
        while (curr) {
            // Check if the current
            // node has a left child
            if (curr->left) {
                // If yes, find the rightmost
                // node in the left subtree
                TreeNode* pre = curr->left;
                while (pre->right) {
                    pre = pre->right;
                }

                // Connect the rightmost node in
                // the left subtree to the current
                //  node's right child
                pre->right = curr->right;

                // Move the entire left subtree to the
                // right child of the current node
                curr->right = curr->left;

                // Set the left child of
                // the current node to NULL
                curr->left = NULL;
            }

            // Move to the next node
            // on the right side
            curr = curr->right;
        }
    }
    void flattenBetter(TreeNode* root) {
        // handle empty tree
        if (root == nullptr)
            return;
        // create stack for DFS
        stack<TreeNode*> st;
        // push root to start traversal
        st.push(root);
        // process while stack has nodes
        while (!st.empty()) {
            // take top node
            TreeNode* cur = st.top();
            // pop it
            st.pop();
            // push right child first (so left is processed first)
            if (cur->right != nullptr)
                st.push(cur->right);
            // push left child next
            if (cur->left != nullptr)
                st.push(cur->left);
            // if stack not empty, link current's right to next node
            if (!st.empty())
                cur->right = st.top();
            // nullify left to form right-only chain
            cur->left = nullptr;
        }
    }
    TreeNode* prev = nullptr;
    void flattenBruteForce(TreeNode* root) {
        // return if node is null
        if (root == nullptr)
            return;
        // flatten right subtree first
        flatten(root->right);
        // flatten left subtree next
        flatten(root->left);
        // connect current node's right to previously processed node
        root->right = prev;
        // nullify left pointer
        root->left = nullptr;
        // update previous to current
        prev = root;
    }

public:
    void flatten(TreeNode* root) {
        return flattenOptmal(root);
    }
};