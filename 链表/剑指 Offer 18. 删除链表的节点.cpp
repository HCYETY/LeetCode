/*
�������������ͷָ���һ��Ҫɾ���Ľڵ��ֵ������һ������ɾ���ýڵ㡣
����ɾ����������ͷ�ڵ㡣

ʾ�� 1:
����: head = [4,5,1,9], val = 5
���: [4,1,9]
����: ������������ֵΪ 5 �ĵڶ����ڵ㣬��ô�ڵ�������ĺ���֮�󣬸�����Ӧ��Ϊ 4 -> 1 -> 9.

ʾ�� 2:
����: head = [4,5,1,9], val = 1
���: [4,5,9]
����: ������������ֵΪ 1 �ĵ������ڵ㣬��ô�ڵ�������ĺ���֮�󣬸�����Ӧ��Ϊ 4 -> 5 -> 9.

˵����
��Ŀ��֤�����нڵ��ֵ������ͬ
��ʹ�� C �� C++ ���ԣ��㲻��Ҫ free �� delete ��ɾ���Ľڵ�
*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// �ֲڰ�
class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        if(head->val == val) return head->next;
        ListNode* pre = head, *cur = head -> next;
        while(cur) {
            if(cur -> val != val) {
                pre = cur;
                cur = cur -> next;
            } else {
                if(cur -> next != NULL) {
                    pre -> next = cur -> next;
                } else {
                    pre -> next = NULL;
                }
                break;
            }
        }
        return head;
    }
};
// ���Ű�
class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        if(head->val == val) return head -> next;
        ListNode *pre = head, *cur = head->next;
        while(cur != nullptr && cur->val != val) {
            pre = cur;
            cur = cur->next;
        }
        if(cur != nullptr) pre->next = cur->next;
        return head;
    }
};
