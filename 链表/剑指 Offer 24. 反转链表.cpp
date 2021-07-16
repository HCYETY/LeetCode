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
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* ret = reverseList(head->next);
		  // 下一个节点指向当前节点
        head->next->next = head;
		  // 尾结点定为 NULL
        head->next = NULL;
        return ret;
    }
};
