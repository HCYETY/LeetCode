/*
����һ�������ͷ�ڵ㣬��β��ͷ����������ÿ���ڵ��ֵ�������鷵�أ���

ʾ�� 1��
���룺head = [1,3,2]
�����[2,3,1]

���ƣ�
0 <= ������ <= 10000
*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
// �ⷨһ����ת����
class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
		  // curΪ��ת�������
        ListNode* cur = NULL;
        ListNode* tmp;
        while(head) {
        		// ��ת�����ѭ������ʽ
            tmp = head -> next;
            head -> next = cur;
            cur = head;
            head = tmp;
        }
		  // ���� head ����
        head = cur;
        vector<int> res;
        while(head) {
            res.push_back(head->val);
            head = head -> next;
        }
        return res;
    }
};
// �ⷨ��������ջ��
class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        stack<int> mystack;
        while(head) {
            mystack.push(head->val);
            head = head -> next;
        } // ��ʱ����ջ���ֵ��ջ�׵�ջ��Ϊ���������
        vector<int> res;
		  // ���ǽ�ջ����ֵһ��һ��ѹ�����飬���ܽ�����ת������
        while(!mystack.empty()) {
            res.push_back(mystack.top());
            mystack.pop();
        }
        return res;
    }
};
// �ⷨ�����ݹ鷨
class Solution {
public:
    void resolve(vector<int>&res, ListNode*head) {
        if(!head) return;
        resolve(res, head->next);
        res.push_back(head->val);
    }
    vector<int> reversePrint(ListNode* head) {
        vector<int>res;
        resolve(res, head);
        return res;
    }
};
