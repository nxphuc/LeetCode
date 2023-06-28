// Title: Sort List
// Source: https://leetcode.com/problems/sort-list
// Difficulty: Medium
// Tags: Linked List, Two Pointers, Divide and Conquer, Sorting, Merge Sort
// Author: nxphuc
// Time Complexity: O(NlogN)
// Space Complexity: O(logN)
// Note: 

/**
 * Given the head of a linked list, return the list after sorting it in ascending order.
 *  
 * Example 1:
 * 
 * Input: head = [4,2,1,3]
 * Output: [1,2,3,4]
 * Example 2:
 * 
 * Input: head = [-1,5,3,4,0]
 * Output: [-1,0,3,4,5]
 * Example 3:
 * Input: head = []
 * Output: []
 *  
 * Constraints:
 * - The number of nodes in the list is in the range [0, 5 * 10^4].
 * - -10^5 <= Node.val <= 10^5
 *  
 * Follow up: Can you sort the linked list in O(n logn) time and O(1) memory (i.e. constant space)?
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
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* merge(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode();
        ListNode *cur = dummy;
        while (list1 && list2) {
            if (list1->val < list2->val) {
                cur->next = list1;
                list1 = list1->next;
            }
            else {
                cur->next = list2;
                list2 = list2->next;
            }
            cur = cur->next;
        }
        if (list1) cur->next = list1;
        else cur->next = list2;
        cur = dummy->next;
        delete dummy;
        return cur;
    }

    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* mid = middleNode(head);
        ListNode* list2 = sortList(mid->next);
        mid->next = nullptr;
        ListNode* list1 = sortList(head);
        return merge(list1, list2);
    }
};