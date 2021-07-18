/*
定义一个函数，输入一个链表的头节点，反转该链表并输出反转后链表的头节点。

示例
输入: 1->2->3->4->5->NULL
输出: 5->4->3->2->1->NULL

限制：
0 <= 节点个数 <= 5000
*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
// 迭代法
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* cur = NULL;
        while(head != NULL) {
			// 反转链表的循环不变式
			
				// tmp 用来保存 head 的下一个节点
            ListNode* tmp = head -> next;
            // head 的下一个节点指向 cur
            head -> next = cur;
            // cur 和 head 分别都往后移一位
            cur = head;
            head = tmp;
        }
        return cur;
    }
};
// 递归法
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
		  // 遇到最后的节点就开始 return ，此时 head 为5
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* ret = reverseList(head->next);
		  // 对题目示例来说，这里的 head 是 4，并不是 5 ，因为 5 在递归判断语句下已经 return 了
		  // 所以需要注意：是 4 的下一个节点也就是 5 ，5 的下一个节点要指向 4 ，这样才能实现反转
        head->next->next = head;
		  // 然后 4 的下一个节点更改指向为 NULL ，相当于尾结点
        head->next = NULL;
        return ret;
    }
};
