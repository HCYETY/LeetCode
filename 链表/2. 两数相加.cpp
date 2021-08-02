/*
�������� �ǿ� ��������ʾ�����Ǹ�������������ÿλ���ֶ��ǰ��� ���� �ķ�ʽ�洢�ģ�����ÿ���ڵ�ֻ�ܴ洢 һλ ���֡�
���㽫��������ӣ�������ͬ��ʽ����һ����ʾ�͵�����
����Լ���������� 0 ֮�⣬���������������� 0 ��ͷ��

ʾ�� 1��
���룺l1 = [2,4,3], l2 = [5,6,4]
�����[7,0,8]
���ͣ�342 + 465 = 807.

ʾ�� 2��
���룺l1 = [0], l2 = [0]
�����[0]

ʾ�� 3��
���룺l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
�����[8,9,9,9,0,0,0,1]

��ʾ��
ÿ�������еĽڵ����ڷ�Χ [1, 100] ��
0 <= Node.val <= 9
��Ŀ���ݱ�֤�б��ʾ�����ֲ���ǰ����
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		  // ����������������ڵ㣬һ����Ϊ�˵õ� l1 �� l2 ��Ӻ��������һ����Ϊ�˷��ؽ������
        ListNode *head = nullptr, *tail = nullptr;
        int carry = 0;
        while (l1 || l2) {
            int n1 = l1 ? l1->val: 0;
            int n2 = l2 ? l2->val: 0;
            int sum = n1 + n2 + carry;
            if (!head) {
					 // head = tail����ʱ���ߵ����õ�ַ����ͬ��
                head = tail = new ListNode(sum % 10);
            } else {
                tail->next = new ListNode(sum % 10);
                tail = tail->next;
            }
            carry = sum / 10;
            if (l1) {
                l1 = l1->next;
            }
            if (l2) {
                l2 = l2->next;
            }
        }
        // l1 �� l2�����λ����н�λ�Ļ�����Ҫ����һ���ڵ�
        if (carry > 0) {
            tail->next = new ListNode(carry);
        }
        return head;
    }
};
