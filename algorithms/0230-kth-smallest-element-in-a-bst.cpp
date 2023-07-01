// Title: Kth Smallest Element in a BST
// Source: https://leetcode.com/problems/kth-smallest-element-in-a-bst
// Difficulty: Medium
// Tags: Tree, Depth-First Search, Binary Search Tree, Binary Tree
// Author: nxphuc
// Time Complexity: O(h + k)
// Space Complexity: O(h)
// Note: 

/**
 * Given the root of a binary search tree, and an integer k, return the k^th smallest value (1-indexed) of all the values of the nodes in the tree.
 *  
 * Example 1:
 * 
 * Input: root = [3,1,4,null,2], k = 1
 * Output: 1
 * Example 2:
 * 
 * Input: root = [5,3,6,2,4,null,null,1], k = 3
 * Output: 3
 *  
 * Constraints:
 * - The number of nodes in the tree is n.
 * - 1 <= k <= n <= 10^4
 * - 0 <= Node.val <= 10^4
 *  
 * Follow up: If the BST is modified often (i.e., we can do insert and delete operations) and you need to find the kth smallest frequently, how would you optimize?
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
    void pushLeft(stack<TreeNode*>& st, TreeNode* root) {
        while (root) {
            st.push(root);
            root = root->left;
        }
    }
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> st;
        pushLeft(st, root);
        while (--k) {
            root = st.top();
            st.pop();
            pushLeft(st, root->right);
        }
        return st.top()->val;
    }
};