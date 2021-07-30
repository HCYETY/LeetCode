/*
����һ�����������е�����������������ͷ�ڵ� head
����ɾ�����������д��������ظ�����Ľڵ㣬ֻ����ԭʼ������ û���ظ����� �����֡�
����ͬ�����������еĽ������

ʾ�� 1��
���룺head = [1,2,3,3,4,4,5]
�����[1,2,5]

ʾ�� 2��
���룺head = [1,1,1,2,3]
�����[2,3]

��ʾ��
�����нڵ���Ŀ�ڷ�Χ [0, 300] ��
-100 <= Node.val <= 100
��Ŀ���ݱ�֤�����Ѿ�����������
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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) {
            return head;
        }
        ListNode* dummy = new ListNode(0, head);
        ListNode* cur = dummy;
        while (cur->next && cur->next->next) {
            if (cur->next->val == cur->next->next->val) {
                int x = cur->next->next->val;
                while (cur->next && cur->next->val == x) {
                    cur->next = cur->next->next;
                }
            } else {
                cur = cur->next;
            }
        }
        return dummy->next;
    }
};
