// Title: All Nodes Distance K in Binary Tree
// Source: https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree
// Difficulty: Medium
// Tags: Tree, Depth-First Search, Breadth-First Search, Binary Tree
// Author: nxphuc
// Time Complexity: O(N)
// Space Complexity: O(N)
// Note: 

/**
 * Given the root of a binary tree, the value of a target node target, and an integer k, return an array of the values of all nodes that have a distance k from the target node.
 * You can return the answer in any order.
 *  
 * Example 1:
 * 
 * Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, k = 2
 * Output: [7,4,1]
 * Explanation: The nodes that are a distance 2 from the target node (with value 5) have values 7, 4, and 1.
 * Example 2:
 * Input: root = [1], target = 1, k = 3
 * Output: []
 *  
 * Constraints:
 * - The number of nodes in the tree is in the range [1, 500].
 * - 0 <= Node.val <= 500
 * - All the values Node.val are unique.
 * - target is the value of one of the nodes in the tree.
 * - 0 <= k <= 1000
**/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void addParent(unordered_map<TreeNode*, TreeNode*>& parent, TreeNode* u, TreeNode* p = nullptr) {
        if (!u) return;
        if (p) parent[u] = p;
        addParent(parent, u->left, u);
        addParent(parent, u->right, u);
    };

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent;

        addParent(parent, root, nullptr);

        vector<int> res;
        queue<TreeNode*> q;
        unordered_set<TreeNode*> visited;
        q.push(target);
        visited.insert(target);
        for (int i = 0; i <= k; ++i) {
            int n = q.size();
            for (int j = 0; j < n; ++j) {
                TreeNode* node = q.front();
                q.pop();
                if (i == k)
                    res.push_back(node->val);
                else {
                    if (node->left != nullptr && visited.find(node->left) == visited.end()) {
                        visited.insert(node->left);
                        q.push(node->left);
                    }
                    if (node->right != nullptr && visited.find(node->right) == visited.end()) {
                        visited.insert(node->right);
                        q.push(node->right);
                    }
                    if (parent.find(node) != parent.end() && visited.find(parent[node]) == visited.end()) {
                        visited.insert(parent[node]);
                        q.push(parent[node]);
                    }
                }
            }
        }
        return res;
    }
};