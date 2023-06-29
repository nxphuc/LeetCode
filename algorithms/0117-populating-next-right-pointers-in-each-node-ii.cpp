// Title: Populating Next Right Pointers in Each Node II
// Source: https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii
// Difficulty: Medium
// Tags: Linked List, Tree, Depth-First Search, Breadth-First Search, Binary Tree
// Author: nxphuc
// Time Complexity: O(N)
// Space Complexity: O(1)
// Note: 

/**
 * Given a binary tree
 * struct Node {
 *   int val;
 *   Node *left;
 *   Node *right;
 *   Node *next;
 * }
 * Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.
 * Initially, all next pointers are set to NULL.
 *  
 * Example 1:
 * 
 * Input: root = [1,2,3,4,5,null,7]
 * Output: [1,#,2,3,#,4,5,7,#]
 * Explanation: Given the above binary tree (Figure A), your function should populate each next pointer to point to its next right node, just like in Figure B. The serialized output is in level order as connected by the next pointers, with '#' signifying the end of each level.
 * Example 2:
 * Input: root = []
 * Output: []
 *  
 * Constraints:
 * - The number of nodes in the tree is in the range [0, 6000].
 * - -100 <= Node.val <= 100
 *  
 * Follow-up:
 * - You may only use constant extra space.
 * - The recursive approach is fine. You may assume implicit stack space does not count as extra space for this problem.
**/

#include <bits/stdc++.h>
using namespace std;


// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        Node* level = root;
        Node *nextHead = nullptr;
        Node *nextTail = nullptr;

        auto link = [&](Node*& node) {
            if (nextHead == nullptr) {
                nextHead = nextTail = node;
                return;
            }
            nextTail->next = node;
            nextTail = node;
        };
        
        while (level) {
            nextHead = nextTail = nullptr;
            Node* cur = level;

            while (cur) {
                if (cur->left) link(cur->left);
                if (cur->right) link(cur->right);
                cur = cur->next;
            }
            level = nextHead;
        }
        return root;
    }
};