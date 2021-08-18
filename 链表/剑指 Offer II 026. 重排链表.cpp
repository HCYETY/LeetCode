/*
给定一个单链表 L 的头节点 head ，单链表 L 表示为： L0 → L1 → … → Ln-1 → Ln
请将其重新排列后变为：L0 → Ln → L1 → Ln-1 → L2 → Ln-2 → …
不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。

示例 1:
输入: head = [1,2,3,4]
输出: [1,4,2,3]

示例 2:
输入: head = [1,2,3,4,5]
输出: [1,5,2,4,3]

提示：
链表的长度范围为 [1, 5 * 104]
1 <= node.val <= 1000
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
    void reorderList(ListNode* head) {
        if(head == nullptr) return;
        // 使用双端队列存储，方便后面操作
        deque <ListNode*> dq;
        ListNode* cur = head;
        while(cur) {
            dq.push_back(cur);
            cur = cur -> next;
        }
        int count = 0;
        // 新建链表，保存重排后的新链表
        ListNode* dummy = new ListNode(), * ret = dummy;
		  // count为奇数，新链表指向最后一个元素；若为偶数，则新链表指向第一个元素
        while(dq.size()) {
            if(count % 2 == 0) {
                ret -> next = dq.front();
                dq.pop_front();
            } else {
                ret -> next = dq.back();
                dq.pop_back();
            }
            count++;
            ret = ret -> next;
        }
        ret -> next = nullptr;
        head = dummy -> next;
    }
};
