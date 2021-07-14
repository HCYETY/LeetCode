/*
输入一个链表，输出该链表中倒数第k个节点。为了符合大多数人的习惯，本题从1开始计数，即链表的尾节点是倒数第1个节点。
例如，一个链表有 6 个节点，从头节点开始，它们的值依次是 1、2、3、4、5、6。
这个链表的倒数第 3 个节点是值为 4 的节点。

示例：
给定一个链表: 1->2->3->4->5, 和 k = 2.
返回链表 4->5.
*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// 双指针求法
// 设置两个指针 slow 和 fast，让 fast 指针先走k步，之后两个指针统一走一步，当 fast 走到链尾时，结束循环
// 此时 slow 指向的结点就是倒数第 k 个结点
class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode * slow = head;
        ListNode * fast = slow;
        while(k > 0) {
            fast = fast -> next;
            k--;
        }
        while(fast) {
            slow = slow -> next;
            fast = fast -> next;
        }
        return slow;
    }
};




/* 面试题 02.02. 返回倒数第 k 个节点
实现一种算法，找出单向链表中倒数第 k 个节点。返回该节点的值。
注意：本题相对原题稍作改动

示例：
输入： 1->2->3->4->5 和 k = 2
输出： 4

说明：
给定的 k 保证是有效的。
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// 递归写法
class Solution {
public:
    int size = 0;
    int kthToLast(ListNode* head, int k) {
        if(!head) return 0;
        int value = kthToLast(head -> next, k);
        size++;
        if(size == k) {
            return head -> val;
        } else {
            return value;
        }
    }
};
