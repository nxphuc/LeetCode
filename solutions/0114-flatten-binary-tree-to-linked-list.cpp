// Title: Flatten Binary Tree to Linked List
// Source: https://leetcode.com/problems/flatten-binary-tree-to-linked-list
// Difficulty: Medium
// Tags: Linked List, Stack, Tree, Depth-First Search, Binary Tree
// Author: nxphuc
// Time Complexity: O(N)
// Space Complexity: O(1)
// Note: 

/**
 * Given the root of a binary tree, flatten the tree into a "linked list":
 * - The "linked list" should use the same TreeNode class where the right child pointer points to the next node in the list and the left child pointer is always null.
 * - The "linked list" should be in the same order as a pre-order traversal of the binary tree.
 *  
 * Example 1:
 * 
 * Input: root = [1,2,5,3,4,null,6]
 * Output: [1,null,2,null,3,null,4,null,5,null,6]
 * Example 2:
 * Input: root = []
 * Output: []
 * Example 3:
 * Input: root = [0]
 * Output: [0]
 *  
 * Constraints:
 * - The number of nodes in the tree is in the range [0, 2000].
 * - -100 <= Node.val <= 100
 *  
 * Follow up: Can you flatten the tree in-place (with O(1) extra space)?
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
    void flatten(TreeNode* root) {
        while (root) {
            if (root->left) {
                TreeNode* prev = root->left;
                while (prev->right) prev = prev->right;
                // move the right subtree under the left subtree
                prev->right = root->right;
                // move all children to the right
                root->right = root->left;
                root->left = nullptr;
            }
            root = root->right;
        }
    }
};