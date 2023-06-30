// Title: Remove Linked List Elements
// Source: https://leetcode.com/problems/remove-linked-list-elements
// Difficulty: Easy
// Tags: Linked List, Recursion
// Author: nxphuc
// Time Complexity: 
// Space Complexity: 
// Note: 

/**
 * Given the head of a linked list and an integer val, remove all the nodes of the linked list that has Node.val == val, and return the new head.
 *  
 * Example 1:
 * 
 * Input: head = [1,2,6,3,4,5,6], val = 6
 * Output: [1,2,3,4,5]
 * Example 2:
 * Input: head = [], val = 1
 * Output: []
 * Example 3:
 * Input: head = [7,7,7,7], val = 7
 * Output: []
 *  
 * Constraints:
 * - The number of nodes in the list is in the range [0, 10^4].
 * - 1 <= Node.val <= 50
 * - 0 <= val <= 50
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

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummy = new ListNode();
        ListNode* last = dummy;
        while (head) {
            if (head->val != val) {
                last->next = head;
                head = head->next;
                last = last->next;
            }
            else {
                ListNode* temp = head->next;
                delete head;
                head = temp;
            }
        }
        last->next = nullptr;
        return dummy->next;
    }
};