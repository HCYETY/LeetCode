/*
����һ������ɾ������ĵ����� n ����㣬���ҷ��������ͷ��㡣
���ף����ܳ���ʹ��һ��ɨ��ʵ����

ʾ�� 1��
���룺head = [1,2,3,4,5], n = 2
�����[1,2,3,5]

ʾ�� 2��
���룺head = [1], n = 1
�����[]

ʾ�� 3��
���룺head = [1,2], n = 1
�����[1]

��ʾ��
�����н�����ĿΪ sz
1 <= sz <= 30
0 <= Node.val <= 100
1 <= n <= sz
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
// �ⷨһ������������
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
		  // �ȼ��������ĳ���
        int len = 0;
        ListNode* cur = head;
        while(cur) {
            len++;
            cur = cur -> next;
        }
        // �½�һ������
        ListNode* res = new ListNode(0);
        res -> next = head;
        ListNode* sign = res;
        // ����n���ڵ��ǰһ���ڵ��˳�ѭ��
        for(int i = 0; i < len - n; i++) {
            sign = sign -> next;
        }
        // �޸Ľڵ��ָ��ָ���n���ڵ����һ���ڵ�
        sign -> next = sign -> next -> next;
        return res -> next;
    }
};
// �ⷨ����ʹ��ջ
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* res = new ListNode(0, head);
        stack<ListNode*> stk;
        ListNode* cur = res;
        // ����������ѹ��ջ��
        while (cur) {
            stk.push(cur);
            cur = cur->next;
        }
        // �Ƴ������� n ���ڵ�
        for (int i = 0; i < n; ++i) {
            stk.pop();
        }
        // ������n���ڵ��ǰһ���ڵ� ָ�� ������n���ڵ�ĺ�һ���ڵ�
        ListNode* prev = stk.top();
        prev->next = prev->next->next;
        return res -> next;
        // �������ķ���ֵ��
        // ListNode* ans = res->next;
        // delete res;
        // return ans;
    }
};
// �ⷨ����˫ָ��
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* cur = new ListNode(0);
        cur -> next = head;
		  // ���ÿ���ָ�룬�� fast ָ���ߵ� ������n���ڵ� ��ǰһ���ڵ�ʱ���˳�ѭ��
        ListNode* slow = cur;
        ListNode* fast = cur;
        for( int i = 0 ; i <= n ; i ++ ){
            fast = fast->next;
        }
        // ��ʱfastָ���Ѿ�ͣ��������slow��fastָ����ͳһ���������ƣ�ֱ��fastָ���ߵ�β���
        // ��ʱslowָ����Ѿ��ߵ� ������n���ڵ��ǰһ���ڵ� ��
        while(fast){
            slow = slow -> next;
            fast = fast -> next;
        }
        // ���ǿ���ֱ��ɾ��Ŀ��ڵ�
        slow -> next = slow -> next -> next;
        ListNode* retNode = cur->next;
        delete cur;
        return retNode;
		  // return cur -> next;
    }
};
