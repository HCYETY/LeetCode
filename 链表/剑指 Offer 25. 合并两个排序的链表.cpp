/*
输入两个递增排序的链表，合并这两个链表并使新链表中的节点仍然是递增排序的。

示例1：
输入：1->2->4, 1->3->4
输出：1->1->2->3->4->4

限制：
0 <= 链表长度 <= 1000
*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
 　     // 新建一个头结点为 0 的链表，用于合并。最后输出的时候不要包括值为 0 的头结点就行了
        ListNode* cur = new ListNode(0);
        ListNode* res = cur;
        while(l1 && l2) {
            if(l1 -> val <= l2 -> val) {
                res -> next = l1;
                l1 = l1 -> next;
            } else {
                res -> next = l2;
                l2 = l2 -> next;
            }
            res = res -> next;
        }
        // 由于 while 循环的判断条件，所以要么 l1 有剩余节点没遍历，要么 l2 有剩余节点没遍历
        // 如果 l1 还有剩余节点没遍历，则直接把 l1 剩下的节点接上
        if(l1) res -> next = l1;
        // 如果 l2 还有剩余节点没遍历，则直接把 l2 剩下的节点接上
        if(l2) res -> next = l2;
		  // 注意这里不是 return cur 。如果这样的话，就会把节点值为 0 的头节点也包括进去
        return cur -> next;
    }
};
