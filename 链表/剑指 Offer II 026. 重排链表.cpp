/*
����һ�������� L ��ͷ�ڵ� head �������� L ��ʾΪ�� L0 �� L1 �� �� �� Ln-1 �� Ln
�뽫���������к��Ϊ��L0 �� Ln �� L1 �� Ln-1 �� L2 �� Ln-2 �� ��
����ֻ�ǵ����ĸı�ڵ��ڲ���ֵ��������Ҫʵ�ʵĽ��нڵ㽻����

ʾ�� 1:
����: head = [1,2,3,4]
���: [1,4,2,3]

ʾ�� 2:
����: head = [1,2,3,4,5]
���: [1,5,2,4,3]

��ʾ��
����ĳ��ȷ�ΧΪ [1, 5 * 104]
1 <= node.val <= 1000
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
    void reorderList(ListNode* head) {
        if(head == nullptr) return;
        // ʹ��˫�˶��д洢������������
        deque <ListNode*> dq;
        ListNode* cur = head;
        while(cur) {
            dq.push_back(cur);
            cur = cur -> next;
        }
        int count = 0;
        // �½������������ź��������
        ListNode* dummy = new ListNode(), * ret = dummy;
		  // countΪ������������ָ�����һ��Ԫ�أ���Ϊż������������ָ���һ��Ԫ��
        while(dq.size()) {
            if(count % 2 == 0) {
                ret -> next = dq.front();
                dq.pop_front();
            } else {
                ret -> next = dq.back();
                dq.pop_back();
            }
            count++;
            ret = ret -> next;
        }
        ret -> next = nullptr;
        head = dummy -> next;
    }
};
