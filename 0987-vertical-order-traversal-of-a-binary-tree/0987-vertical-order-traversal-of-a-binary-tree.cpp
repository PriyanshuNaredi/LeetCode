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
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> nodes; // vertical, level, node_val
        /*
        nodes = {
            -1: {
                1: {9}
            },
            0: {
                0: {3},
                2: {15}
            }
            nodes[0][0] = {3}
        }
        */
        queue<pair<TreeNode*, pair<int, int>>> todo; // node, vertical, level

        // store all the nodes in map based on there levels
        todo.push({root, {0, 0}});

        while (!todo.empty()) {
            auto p = todo.front();
            todo.pop();
            TreeNode* node = p.first;
            int x = p.second.first, y = p.second.second;

            nodes[x][y].insert(node->val);

            if (node->left)
                todo.push({node->left, {x - 1, y + 1}});

            if (node->right)
                todo.push({node->right, {x + 1, y + 1}});
        }

        vector<vector<int>> ans;
        for (auto p : nodes) { // iterate x (columns)
            vector<int> col;
            for (auto q : p.second) { // iterate y (levels)
                // add all values
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(col);
        }

        return ans;
    }
};