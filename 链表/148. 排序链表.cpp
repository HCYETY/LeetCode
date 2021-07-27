/*
给你链表的头结点 head，请将其按 升序 排列并返回 排序后的链表 。

进阶：
你可以在 O(n logn) 时间复杂度和常数级空间复杂度下，对链表进行排序吗？

示例 1：
输入：head = [4,2,1,3]
输出：[1,2,3,4]

示例 2：
输入：head = [-1,5,3,4,0]
输出：[-1,0,3,4,5]

示例 3：
输入：head = []
输出：[]

提示：
链表中节点的数目在范围?[0, 5 * 104] 内
-105 <= Node.val <= 105
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
// 自顶向下的归并排序
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        return sort_list(head, nullptr);
    }
    ListNode* sort_list(ListNode* head, ListNode* sign) {
        if(head == nullptr) {
            return head;
        }
        if(head -> next == sign) {
            head -> next = nullptr;
            return head;
        }
        ListNode* slow = head, * fast = head;
        while(fast != sign) {
            fast = fast -> next;
            slow = slow -> next;
            if(fast != sign) {
                fast = fast -> next;
            }
        }
        ListNode* mid = slow;
        return merge(sort_list(head, mid), sort_list(mid, sign));
    }
    ListNode* merge(ListNode* list1, ListNode* list2) {
        ListNode* cur = new ListNode(0);
        ListNode* res = cur, *tmp1 = list1, *tmp2 = list2;
        while(tmp1 != nullptr && tmp2 != nullptr) {
            if(tmp1 -> val <= tmp2 -> val) {
                res -> next = tmp1;
                tmp1 = tmp1 -> next;
            } else {
                res -> next = tmp2;
                tmp2 = tmp2 -> next;
            }
            res = res -> next;
        }
        if(tmp1 != nullptr) {
            res -> next = tmp1;
        } else {
            res -> next = tmp2;
        }
        return cur -> next;
    }
};
