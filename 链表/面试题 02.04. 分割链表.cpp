/*
����һ�������ͷ�ڵ� head ��һ���ض�ֵ x ��
�����������зָ���ʹ������ С�� x �Ľڵ㶼������ ���ڻ���� x �Ľڵ�֮ǰ��
��Ӧ�� ���� ����������ÿ���ڵ�ĳ�ʼ���λ�á�

ʾ�� 1��
���룺head = [1,4,3,2,5,2], x = 3
�����[1,2,2,4,3,5]

ʾ�� 2��
���룺head = [2,1], x = 2
�����[1,2]

��ʾ��
�����нڵ����Ŀ�ڷ�Χ [0, 200] ��
-100 <= Node.val <= 100
-200 <= x <= 200
*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// ˼·��
// �½���������big �洢�ڵ�ֵ���ڻ���� x �ģ�small �洢�ڵ�ֵС�� x ��
// ������ head �����big �� small ����Ҳ�����ڵ�ĳ�ʼ���λ�÷���洢���
// ��ʱsmall ������� big ��������Ŀ����
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* small = new ListNode(0), * smallHash = small;
        ListNode* big = new ListNode(0), * bigHash = big;
        while(head) {
            if(head -> val >= x) {
                big -> next = head;
                big = big -> next;
            } else {
                small -> next = head;
                small = small -> next;
            }
            head = head -> next;
        }
        big -> next = NULL;
        small -> next = bigHash -> next;
        return smallHash -> next;
    }
};
