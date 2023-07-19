// Title: Add Two Numbers II
// Source: https://leetcode.com/problems/add-two-numbers-ii
// Difficulty: Medium
// Tags: Linked List, Math, Stack
// Author: nxphuc
// Time Complexity: O(N + M)
// Space Complexity: O(1)
// Note: 

/**
 * You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
 * You may assume the two numbers do not contain any leading zero, except the number 0 itself.
 *  
 * Example 1:
 * 
 * Input: l1 = [7,2,4,3], l2 = [5,6,4]
 * Output: [7,8,0,7]
 * Example 2:
 * Input: l1 = [2,4,3], l2 = [5,6,4]
 * Output: [8,0,7]
 * Example 3:
 * Input: l1 = [0], l2 = [0]
 * Output: [0]
 *  
 * Constraints:
 * - The number of nodes in each linked list is in the range [1, 100].
 * - 0 <= Node.val <= 9
 * - It is guaranteed that the list represents a number that does not have leading zeros.
 *  
 * Follow up: Could you solve it without reversing the input lists?
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

/**
 * Solution 1: reverse list with O(1) extra space
*/
// class Solution {
// public:
//     ListNode* reverseList(ListNode* head) {
//         ListNode* dummy = new ListNode();
//         ListNode* temp;
//         while (head) {
//             temp = head->next;
//             head->next = dummy->next;
//             dummy->next = head;
//             head = temp;
            
//         }
//         return dummy->next;
//     }

//     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//         l1 = reverseList(l1);
//         l2 = reverseList(l2);
//         ListNode* cur1 = l1;
//         ListNode* cur2 = l2;
//         ListNode* head = nullptr;
//         int rem = 0;
//         while (cur1 || cur2) {
//             if (cur1) {
//                 rem += cur1->val;
//                 cur1 = cur1->next;
//             }
//             if (cur2) {
//                 rem += cur2->val;
//                 cur2 = cur2->next;
//             }
//             head = new ListNode(rem % 10, head);
//             rem /= 10;
//         }
//         if (rem)
//             return new ListNode(rem, head);
//         return head;
//     }
// };

/**
 * Solution 2: use stack as follow up with O(N + M) extra sapce
 * I don't know why we need this follow up???
*/
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1, s2;
        while (l1) {
            s1.push(l1->val);
            l1 = l1->next;
        }
        while (l2) {
            s2.push(l2->val);
            l2 = l2->next;
        }
        ListNode* head = nullptr;
        int rem = 0;
        while (!s1.empty() || !s2.empty()) {
            if (!s1.empty()) {
                rem += s1.top();
                s1.pop();
            }
            if (!s2.empty()) {
                rem += s2.top();
                s2.pop();
            }
            head = new ListNode(rem % 10, head);
            rem /= 10;
        }
        if (rem)
            return new ListNode(rem, head);
        return head;
    }
};