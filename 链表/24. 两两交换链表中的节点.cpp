/*
����һ���������������������ڵĽڵ㣬�����ؽ����������
�㲻��ֻ�ǵ����ĸı�ڵ��ڲ���ֵ��������Ҫʵ�ʵĽ��нڵ㽻����

ʾ�� 1��
���룺head = [1,2,3,4]
�����[2,1,4,3]

ʾ�� 2��
���룺head = []
�����[]

ʾ�� 3��
���룺head = [1]
�����[1]

��ʾ��
�����нڵ����Ŀ�ڷ�Χ [0, 100] ��
0 <= Node.val <= 100

���ף������ڲ��޸�����ڵ�ֵ������½�����������?��Ҳ����˵�����޸Ľڵ㱾����
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
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr) return {};
        ListNode* cur = new ListNode(0);
        cur -> next = head;
        ListNode* tmp = cur;  // ��������󷵻���������
        while(tmp -> next != nullptr && tmp -> next -> next != nullptr) {
            ListNode* pre = tmp -> next;  // ��¼����ǰ�ĵ�һ���ڵ�
            ListNode* succ = tmp -> next -> next;  // ��¼����ǰ�ĵڶ����ڵ�
            tmp -> next = succ;  // һ��ʼ���ڱ��ڵ�ָ��ڶ����ڵ�
            pre -> next = succ -> next;  // ��һ���ڵ�ָ��ڶ����ڵ�ĺ�һ���ڵ�
            succ -> next = pre;  // �ڶ����ڵ�ָ���һ���ڵ�
            tmp = pre;  // �����ڱ��ڵ�
        }
        return cur -> next;
    }
};
