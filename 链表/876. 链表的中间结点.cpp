/*
����һ��ͷ���Ϊ head �ķǿյ���������������м��㡣
����������м��㣬�򷵻صڶ����м��㡣

ʾ�� 1��
���룺[1,2,3,4,5]
��������б��еĽ�� 3 (���л���ʽ��[3,4,5])
		���صĽ��ֵΪ 3 �� (����ϵͳ�Ըý�����л������� [3,4,5])��
ע�⣬���Ƿ�����һ�� ListNode ���͵Ķ��� ans��������
		ans.val = 3, ans.next.val = 4, ans.next.next.val = 5, �Լ� ans.next.next.next = NULL.

ʾ�� 2��
���룺[1,2,3,4,5,6]
��������б��еĽ�� 4 (���л���ʽ��[4,5,6])
		���ڸ��б��������м��㣬ֵ�ֱ�Ϊ 3 �� 4�����Ƿ��صڶ�����㡣

��ʾ��
��������Ľ�������� 1 �� 100 ֮�䡣
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
    ListNode* middleNode(ListNode* head) {
        int count = 0;
        ListNode * cur = head;
        while (cur) {
            cur = cur -> next;
            count++;
        }
        cur = head;
        int sign = 0;
        while (sign < count / 2) {
            sign++;
            cur = cur -> next;
        }
        return cur;
    }
};
// �Ż��棺
// ������ָ�� slow �� fast һ���������slow һ����һ����fast һ����������
// ��ô�� fast ���������ĩβʱ��slow ��Ȼλ���м䡣
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode * slow = head;
        ListNode * fast = head;
        while(fast && fast -> next) {
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        return slow;
    }
};
