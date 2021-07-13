/*
����һ������������ý�� head��������ÿ������ֵ���� 0 ���� 1��
��֪��������һ���������ֵĶ����Ʊ�ʾ��ʽ��
���㷵�ظ���������ʾ���ֵ� ʮ����ֵ ��

ʾ�� 1��
���룺head = [1,0,1]
�����5
���ͣ��������� (101) ת��Ϊʮ������ (5)

ʾ�� 2��
���룺head = [0]
�����0

ʾ�� 3��
���룺head = [1]
�����1

ʾ�� 4��
���룺head = [1,0,0,1,0,0,1,1,1,0,0,0,0,0,0]
�����18880

ʾ�� 5��
���룺head = [0,0]
�����0

��ʾ��
����Ϊ�ա�
����Ľ������������ 30��
ÿ������ֵ���� 0 ���� 1��
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
// �ⷨһ�����������ĳ��ȣ��������ֵ�ʮ������
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        ListNode * cur = head;
        int count = 0, res = 0;
        while(cur != nullptr) {
            count++;
            cur = cur -> next;
        }
        cur = head;
        while(cur != nullptr) {
            res += (cur -> val) * pow(2, count - 1);
            count--;
            cur = cur -> next;
        }
        return res;
    }
};
// �ⷨ���������������ȣ��ڱ���һ�������ͬʱ�õ����ֵ�ʮ����ֵ
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        ListNode* cur = head;
        int ans = 0;
        while (cur != nullptr) {
            ans = ans * 2 + cur->val;
            cur = cur -> next;
        }
        return ans;
    }
};
