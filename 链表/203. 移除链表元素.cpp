/*
����һ�������ͷ�ڵ� head ��һ������ val ��
����ɾ���������������� Node.val == val �Ľڵ㣬������ �µ�ͷ�ڵ� ��

ʾ�� 1��
���룺head = [1,2,6,3,4,5,6], val = 6
�����[1,2,3,4,5]

ʾ�� 2��
���룺head = [], val = 1
�����[]

ʾ�� 3��
���룺head = [7,7,7,7], val = 7
�����[]

��ʾ��
�б��еĽڵ���Ŀ�ڷ�Χ [0, 104] ��
1 <= Node.val <= 50
0 <= val <= 50
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
    ListNode* removeElements(ListNode* head, int val) {
        if(!head) return {};
		  // �½�һ��������ͷָ��
        ListNode* cur = new ListNode(0, head), *res = cur;
        while(res -> next) {
            if(res -> next -> val != val) {
                res = res -> next;
            } else {
                res -> next = res -> next -> next;
            }
        }
        return cur -> next;
    }
};
