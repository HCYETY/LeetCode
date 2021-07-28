/*
给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。
你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。

示例 1：
输入：head = [1,2,3,4]
输出：[2,1,4,3]

示例 2：
输入：head = []
输出：[]

示例 3：
输入：head = [1]
输出：[1]

提示：
链表中节点的数目在范围 [0, 100] 内
0 <= Node.val <= 100

进阶：你能在不修改链表节点值的情况下解决这个问题吗?（也就是说，仅修改节点本身。）
*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr) return {};
        ListNode* cur = new ListNode(0);
        cur -> next = head;
        ListNode* tmp = cur;  // 方便在最后返回整个链表
        while(tmp -> next != nullptr && tmp -> next -> next != nullptr) {
            ListNode* pre = tmp -> next;  // 记录交换前的第一个节点
            ListNode* succ = tmp -> next -> next;  // 记录交换前的第二个节点
            tmp -> next = succ;  // 一开始的哨兵节点指向第二个节点
            pre -> next = succ -> next;  // 第一个节点指向第二个节点的后一个节点
            succ -> next = pre;  // 第二个节点指向第一个节点
            tmp = pre;  // 更新哨兵节点
        }
        return cur -> next;
    }
};
