// Title: Palindrome Linked List
// Source: https://leetcode.com/problems/palindrome-linked-list
// Difficulty: Easy
// Tags: Linked List, Two Pointers, Stack, Recursion
// Author: nxphuc
// Time Complexity: O(N)
// Space Complexity: O1
// Note: 

/**
 * Given the head of a singly linked list, return true if it is a palindrome or false otherwise.
 *  
 * Example 1:
 * 
 * Input: head = [1,2,2,1]
 * Output: true
 * Example 2:
 * 
 * Input: head = [1,2]
 * Output: false
 *  
 * Constraints:
 * - The number of nodes in the list is in the range [1, 10^5].
 * - 0 <= Node.val <= 9
 *  
 * Follow up: Could you do it in O(n) time and O(1) space?
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
    ListNode* reverseList(ListNode* head) {
        ListNode* newHead = nullptr;
        while (head) {
            ListNode* temp = head->next;
            head->next = newHead;
            newHead = head;
            head = temp;
        }
        return newHead;
    }

    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    bool isEqual(ListNode* head1, ListNode* head2) {
        while (head2) {
            if (head1->val != head2->val)
                return false;
            head1 = head1->next;
            head2 = head2->next;
        }
        return true;
    }

    bool isPalindrome(ListNode* head) {
        ListNode* midNode = middleNode(head);
        ListNode* head2 = reverseList(midNode->next);
        midNode->next = nullptr;
        return isEqual(head, head2);
    }
};