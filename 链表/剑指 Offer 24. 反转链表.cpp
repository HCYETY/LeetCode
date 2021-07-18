/*
����һ������������һ�������ͷ�ڵ㣬��ת�����������ת�������ͷ�ڵ㡣

ʾ��
����: 1->2->3->4->5->NULL
���: 5->4->3->2->1->NULL

���ƣ�
0 <= �ڵ���� <= 5000
*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
// ������
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* cur = NULL;
        while(head != NULL) {
			// ��ת�����ѭ������ʽ
			
				// tmp �������� head ����һ���ڵ�
            ListNode* tmp = head -> next;
            // head ����һ���ڵ�ָ�� cur
            head -> next = cur;
            // cur �� head �ֱ�������һλ
            cur = head;
            head = tmp;
        }
        return cur;
    }
};
// �ݹ鷨
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
		  // �������Ľڵ�Ϳ�ʼ return ����ʱ head Ϊ5
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* ret = reverseList(head->next);
		  // ����Ŀʾ����˵������� head �� 4�������� 5 ����Ϊ 5 �ڵݹ��ж�������Ѿ� return ��
		  // ������Ҫע�⣺�� 4 ����һ���ڵ�Ҳ���� 5 ��5 ����һ���ڵ�Ҫָ�� 4 ����������ʵ�ַ�ת
        head->next->next = head;
		  // Ȼ�� 4 ����һ���ڵ����ָ��Ϊ NULL ���൱��β���
        head->next = NULL;
        return ret;
    }
};
