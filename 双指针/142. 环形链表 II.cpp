/*
����һ��������������ʼ�뻷�ĵ�һ���ڵ㡣 ��������޻����򷵻� null��
Ϊ�˱�ʾ���������еĻ�������ʹ������ pos ����ʾ����β���ӵ������е�λ�ã������� 0 ��ʼ���� ��� pos �� -1�����ڸ�������û�л���
ע�⣬pos ���������ڱ�ʶ�����������������Ϊ�������ݵ������С�

˵�����������޸ĸ���������

���ף�
���Ƿ����ʹ�� O(1) �ռ������⣿

ʾ�� 1��
���룺head = [3,2,0,-4], pos = 1
�������������Ϊ 1 ������ڵ�
���ͣ���������һ��������β�����ӵ��ڶ����ڵ㡣

ʾ�� 2��
���룺head = [1,2], pos = 0
�������������Ϊ 0 ������ڵ�
���ͣ���������һ��������β�����ӵ���һ���ڵ㡣

ʾ�� 3��
���룺head = [1], pos = -1
��������� null
���ͣ�������û�л���

��ʾ��
�����нڵ����Ŀ��Χ�ڷ�Χ [0, 104] ��
-105 <= Node.val <= 105
pos ��ֵΪ -1 ���������е�һ����Ч����
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
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head, * fast = head;
		  // ��һ������
        while (true) {
            if (fast==NULL || fast->next==NULL) return NULL;
            slow = slow -> next;
            fast = fast -> next -> next;
            if (slow == fast) break;
        }
        fast = head;
        // �ڶ�������
        // ע�⣺slow �Ǵӵ�һ�������ĵ���������ߵģ�fast �Ǵ�ͷ�ߵ�
        while (slow != fast) {
            slow = slow -> next;
            fast = fast -> next;
        }
        // ��ʱ������ʱ�����ڻ��εĵ�һ���ڵ�ͣ������
        return fast;
    }
};
