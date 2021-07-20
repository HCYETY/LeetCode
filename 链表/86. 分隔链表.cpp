/*
����һ�������ͷ�ڵ� head ��һ���ض�ֵ x �������������зָ���ʹ������ С�� x �Ľڵ㶼������ ���ڻ���� x �Ľڵ�֮ǰ��
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
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* small = new ListNode(0), * smallHead = small;
        ListNode* large = new ListNode(0), * largeHead = large;
        while(head) {
            if(head -> val < x) {
                small -> next = head;
                small = small->next;
            } else {
                large -> next = head;
                large = large->next;
            }
            head = head -> next;
        }
        large->next = nullptr;
        small->next = largeHead->next;
        return smallHead -> next;
    }
};
