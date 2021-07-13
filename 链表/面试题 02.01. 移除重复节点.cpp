/*
��д���룬�Ƴ�δ���������е��ظ��ڵ㡣�����ʼ���ֵĽڵ㡣

ʾ��1:
���룺[1, 2, 3, 3, 2, 1]
�����[1, 2, 3]
 
ʾ��2:
���룺[1, 1, 1, 1, 2]
�����[1, 2]

��ʾ��
��������[0, 20000]��Χ�ڡ�
����Ԫ����[0, 20000]��Χ�ڡ�

���ף�
�������ʹ����ʱ������������ô�����
*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// ����һ����ϣ��ֵ
class Solution {
public:
    ListNode* removeDuplicateNodes(ListNode* head) {
        if(!head) return head;
        unordered_set<int> occurred = {head -> val};
        ListNode * cur = head;
        while(cur -> next != nullptr) {
            ListNode * pos = cur -> next;
            if(!occurred.count(pos -> val)) {
                occurred.insert(pos -> val);
                cur = cur -> next;
            } else {
                cur -> next = cur -> next -> next;
            }
        }
        // cur -> next = nullptr;
        return head;
    }
};
// ���װ棺������ð��ѭ�� --> ʱ�任�ռ� O_o??
class Solution {
public:
    ListNode* removeDuplicateNodes(ListNode* head) {
        ListNode* cur = head;
        while (cur != nullptr) {
            ListNode* pos = cur;
            while (pos->next != nullptr) {
                if (pos->next->val == cur->val) {
                    pos->next = pos->next->next;
                } else {
                    pos = pos->next;
                }
            }
            cur = cur -> next;
        }
        return head;
    }
};
