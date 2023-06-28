// Title: Convert Sorted List to Binary Search Tree
// Source: https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree
// Difficulty: Medium
// Tags: Linked List, Divide and Conquer, Tree, Binary Search Tree, Binary Tree
// Author: nxphuc
// Time Complexity: O(N)
// Space Complexity: O(logN)
// Note: 

/**
 * Given the head of a singly linked list where elements are sorted in ascending order, convert it to a height-balanced binary search tree.
 *  
 * Example 1:
 * 
 * Input: head = [-10,-3,0,5,9]
 * Output: [0,-3,9,-10,null,5]
 * Explanation: One possible answer is [0,-3,9,-10,null,5], which represents the shown height balanced BST.
 * Example 2:
 * Input: head = []
 * Output: []
 *  
 * Constraints:
 * - The number of nodes in head is in the range [0, 2 * 10^4].
 * - -10^5 <= Node.val <= 10^5
**/

#include <bits/stdc++.h>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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
    int length(ListNode* head) {
        int cnt = 0;
        while (head) {
            ++cnt;
            head = head->next;
        }
        return cnt;
    }

    TreeNode* sortedListToBST(ListNode* &head, int left, int right) {
        if (left > right) return nullptr;
        int mid = (left + right) / 2;
        TreeNode* root = new TreeNode();
        root->left = sortedListToBST(head, left, mid - 1);
        root->val = head->val;
        head = head->next;
        root->right = sortedListToBST(head, mid + 1, right);
        return root;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        return sortedListToBST(head, 0, length(head) - 1);
    }
};