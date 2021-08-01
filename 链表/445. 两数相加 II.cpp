/*
�������� �ǿ� ���������������Ǹ��������������λλ������ʼλ�á����ǵ�ÿ���ڵ�ֻ�洢һλ���֡�
����������ӻ᷵��һ���µ�����
����Լ���������� 0 ֮�⣬���������ֶ��������㿪ͷ��

ʾ��1��
���룺l1 = [7,2,4,3], l2 = [5,6,4]
�����[7,8,0,7]

ʾ��2��
���룺l1 = [2,4,3], l2 = [5,6,4]
�����[8,0,7]

ʾ��3��
���룺l1 = [0], l2 = [0]
�����[0]

��ʾ��
����ĳ��ȷ�ΧΪ [1, 100]
0 <= node.val <= 9
�������ݱ�֤��������������ǰ�� 0

���ף���������������޸ĸ���δ������仰˵�����ܶ��б��еĽڵ���з�ת��
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
		  // ������ڵ�ֵѹ��ջ
        stack <int> stk1, stk2;
        while(l1) {
            stk1.push(l1 -> val);
            l1 = l1 -> next;
        }
        while(l2) {
            stk2.push(l2 -> val);
            l2 = l2 -> next;
        }
        // ��ʶ�Ƿ��λ
        int carry = 0;
        ListNode* ans = nullptr;
        while(!stk1.empty() || !stk2.empty() || carry != 0) {
            int a = stk1.empty() ? 0 : stk1.top();
            int b = stk2.empty() ? 0 : stk2.top();
            if (!stk1.empty()) stk1.pop();
            if (!stk2.empty()) stk2.pop();
            int cur = a + b + carry;
            carry = cur / 10;
            cur %= 10;
            ListNode* curnode = new ListNode(cur);
            // ��ת����
            curnode -> next = ans;
            ans = curnode;
        }
        return ans;
    }
};
