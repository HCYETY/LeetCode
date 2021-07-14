/*
����һ����������������е�����k���ڵ㡣Ϊ�˷��ϴ�����˵�ϰ�ߣ������1��ʼ�������������β�ڵ��ǵ�����1���ڵ㡣
���磬һ�������� 6 ���ڵ㣬��ͷ�ڵ㿪ʼ�����ǵ�ֵ������ 1��2��3��4��5��6��
�������ĵ����� 3 ���ڵ���ֵΪ 4 �Ľڵ㡣

ʾ����
����һ������: 1->2->3->4->5, �� k = 2.
�������� 4->5.
*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// ˫ָ����
// ��������ָ�� slow �� fast���� fast ָ������k����֮������ָ��ͳһ��һ������ fast �ߵ���βʱ������ѭ��
// ��ʱ slow ָ��Ľ����ǵ����� k �����
class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode * slow = head;
        ListNode * fast = slow;
        while(k > 0) {
            fast = fast -> next;
            k--;
        }
        while(fast) {
            slow = slow -> next;
            fast = fast -> next;
        }
        return slow;
    }
};




/* ������ 02.02. ���ص����� k ���ڵ�
ʵ��һ���㷨���ҳ����������е����� k ���ڵ㡣���ظýڵ��ֵ��
ע�⣺�������ԭ�������Ķ�

ʾ����
���룺 1->2->3->4->5 �� k = 2
����� 4

˵����
������ k ��֤����Ч�ġ�
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// �ݹ�д��
class Solution {
public:
    int size = 0;
    int kthToLast(ListNode* head, int k) {
        if(!head) return 0;
        int value = kthToLast(head -> next, k);
        size++;
        if(size == k) {
            return head -> val;
        } else {
            return value;
        }
    }
};
