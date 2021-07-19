/*
����һ�����������е�����������������ͷ�ڵ� head ������ɾ�������ظ���Ԫ�أ�ʹÿ��Ԫ�� ֻ����һ�� ��
����ͬ�����������еĽ������

ʾ�� 1��
���룺head = [1,1,2]
�����[1,2]

ʾ�� 2��
���룺head = [1,1,2,3,3]
�����[1,2,3]

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
        if(head == nullptr) return {};
        ListNode* pre = head, *cur = head -> next;
        while(cur) {
            if(pre -> val != cur -> val) {
                pre = cur;
                cur = cur -> next;
            } else {
                pre -> next = cur -> next;
                cur = cur -> next;
            }
        }
        return head;
    }
};
