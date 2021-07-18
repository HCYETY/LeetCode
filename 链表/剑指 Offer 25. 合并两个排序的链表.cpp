/*
����������������������ϲ�����������ʹ�������еĽڵ���Ȼ�ǵ�������ġ�

ʾ��1��
���룺1->2->4, 1->3->4
�����1->1->2->3->4->4

���ƣ�
0 <= ������ <= 1000
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
 ��     // �½�һ��ͷ���Ϊ 0 ���������ںϲ�����������ʱ��Ҫ����ֵΪ 0 ��ͷ��������
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
        // ���� while ѭ�����ж�����������Ҫô l1 ��ʣ��ڵ�û������Ҫô l2 ��ʣ��ڵ�û����
        // ��� l1 ����ʣ��ڵ�û��������ֱ�Ӱ� l1 ʣ�µĽڵ����
        if(l1) res -> next = l1;
        // ��� l2 ����ʣ��ڵ�û��������ֱ�Ӱ� l2 ʣ�µĽڵ����
        if(l2) res -> next = l2;
		  // ע�����ﲻ�� return cur ����������Ļ����ͻ�ѽڵ�ֵΪ 0 ��ͷ�ڵ�Ҳ������ȥ
        return cur -> next;
    }
};
