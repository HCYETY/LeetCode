/*
给你一个链表的头节点 head 和一个特定值 x 。
请你对链表进行分隔，使得所有 小于 x 的节点都出现在 大于或等于 x 的节点之前。
你应当 保留 两个分区中每个节点的初始相对位置。

示例 1：
输入：head = [1,4,3,2,5,2], x = 3
输出：[1,2,2,4,3,5]

示例 2：
输入：head = [2,1], x = 2
输出：[1,2]

提示：
链表中节点的数目在范围 [0, 200] 内
-100 <= Node.val <= 100
-200 <= x <= 200
*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// 思路：
// 新建两种链表，big 存储节点值大于或等于 x 的，small 存储节点值小于 x 的
// 遍历完 head 链表后，big 和 small 链表也都按节点的初始相对位置分类存储完毕
// 此时small 链表接上 big 链表，便达成目的了
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* small = new ListNode(0), * smallHash = small;
        ListNode* big = new ListNode(0), * bigHash = big;
        while(head) {
            if(head -> val >= x) {
                big -> next = head;
                big = big -> next;
            } else {
                small -> next = head;
                small = small -> next;
            }
            head = head -> next;
        }
        big -> next = NULL;
        small -> next = bigHash -> next;
        return smallHash -> next;
    }
};
