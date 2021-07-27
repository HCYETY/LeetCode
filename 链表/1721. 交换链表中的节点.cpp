/*
���������ͷ�ڵ� head ��һ������ k ��
���� ���������� k ���ڵ�͵����� k ���ڵ��ֵ�󣬷��������ͷ�ڵ㣨���� �� 1 ��ʼ��������

ʾ�� 1��
���룺head = [1,2,3,4,5], k = 2
�����[1,4,3,2,5]

ʾ�� 2��
���룺head = [7,9,6,6,7,8,3,0,9,5], k = 5
�����[7,9,6,6,8,7,3,0,9,5]

ʾ�� 3��
���룺head = [1], k = 1
�����[1]

ʾ�� 4��
���룺head = [1,2], k = 1
�����[2,1]

ʾ�� 5��
���룺head = [1,2,3], k = 2
�����[1,2,3]

��ʾ��
�����нڵ����Ŀ�� n
1 <= k <= n <= 105
0 <= Node.val <= 100
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
// ˫ָ��
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* fast = head;
        for(int i = 1 ; i < k ; i ++){
            fast = fast->next;
        }
        ListNode* temp = fast;
        ListNode* slow = head;
        while(fast->next){
            fast = fast->next;
            slow = slow->next;
        }
        swap(slow->val, temp->val);
        return head;
    }
};
//һ��ʼ�����������뽻�������ڵ�ģ�����������⣬ֻ�����ڵ�ֵ���аɣ������ˣ�
//������������в�ͨ����֪���������������Ͼ�����Ѫ���������ں����
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        if(head == nullptr) {
            return head;
        }
        // Ϊ�˵õ�����ĳ���
        int length = 0;
        ListNode* cur = head;
        while(cur != nullptr) {
            length++;
            cur = cur -> next;
        }
        // �½�����1 ������Ŀ��ڵ�
        int len = 0;
        ListNode* sign = head, * pre = nullptr, * lat = nullptr;
        while(sign != nullptr) {
            len++;
            // �ҵ��� k ���ڵ�
            if(len == k) {
                pre = sign;
            }
            // �ҵ�������k���ڵ㣬���滻�ɵ�k���ڵ�
            if(len == length - k) {
                lat = sign -> next;
                sign -> next = pre;
                pre -> next = sign -> next -> next;
                break;
            }
            sign = sign -> next;
        }
        // �½�����2 �滻�� ������k���ڵ�
        len = 0;
        ListNode* res = sign;
        while(res != nullptr) {
            len++;
            if(len == k - 1) {
                res -> next = lat;
                lat -> next = res -> next -> next;
                break;
            }
            res = res -> next;
        }
        return res;
    }
};
