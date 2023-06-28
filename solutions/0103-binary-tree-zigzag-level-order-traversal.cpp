// Title: Binary Tree Zigzag Level Order Traversal
// Source: https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal
// Difficulty: Medium
// Tags: Tree, Breadth-First Search, Binary Tree
// Author: nxphuc
// Time Complexity: O(N)
// Space Complexity: O(N)
// Note: 

/**
 * Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).
 *  
 * Example 1:
 * 
 * Input: root = [3,9,20,null,null,15,7]
 * Output: [[3],[20,9],[15,7]]
 * Example 2:
 * Input: root = [1]
 * Output: [[1]]
 * Example 3:
 * Input: root = []
 * Output: []
 *  
 * Constraints:
 * - The number of nodes in the tree is in the range [0, 2000].
 * - -100 <= Node.val <= 100
**/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> res;
        if (root)
            q.push(root);
        for (int turn = 0; !q.empty(); turn ^= 1) {
            int n = q.size();
            res.push_back({});
            auto& row = res.back();
            while (n--) {
                auto temp = q.front();
                q.pop();
                row.push_back(temp->val);
                if (temp->left) q.push(temp->left);
                if (temp->right) q.push(temp->right);
            }
            if (turn)
                reverse(row.begin(), row.end());
        }
        return res;
    }
};