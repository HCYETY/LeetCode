/*
������������ list1 �� list2 �����ǰ�����Ԫ�طֱ�Ϊ n ���� m ����
���㽫 list1 �е� a ���ڵ㵽�� b ���ڵ�ɾ��������list2 ���ڱ�ɾ���ڵ��λ�á�
���㷵�ؽ�������ͷָ�롣

ʾ�� 1��
���룺list1 = [0,1,2,3,4,5], a = 3, b = 4, list2 = [1000000,1000001,1000002]
�����[0,1,2,1000000,1000001,1000002,5]
���ͣ�����ɾ�� list1 �� ���� �� ���� ���ڵ㣬���� list2 ���ڸ�λ�á�

ʾ�� 2��
���룺list1 = [0,1,2,3,4,5,6], a = 2, b = 5, list2 = [1000000,1000001,1000002,1000003,1000004]
�����[0,1,1000000,1000001,1000002,1000003,1000004,6]

��ʾ��
3 <= list1.length <= 104
1 <= a <= b < list1.length - 1
1 <= list2.length <= 104
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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        int count = 0;
		  // ��Ϊ�������ܸ��ġ�ǰ��·�ߡ���������½������� list1 �� b ���ڵ�������
		  // �� list1 ������ a ���ڵ㲢����һ��ָ��ָ�� list2 �󣬾Ϳ��Խ�������½�������
        ListNode* pre = list1, * sign = nullptr;
        while(pre) {
            if(count != b) {
                pre = pre -> next;
                count++;
            } else {
                sign = pre -> next;
					 // ���� count ,��������ظ�����
                count = 0;
                break;
            }
        }
        // �½��������㴦�� a==0 �������
        ListNode* cur =  new ListNode(0, list1), * res = cur;
        while(res -> next) {
            if(count != a) {
                res = res -> next;
                count++;
            } else {
                res -> next = list2;
                break;
            }
        }
		  // ��ʱ list2 �Ѿ����� res ���ϣ������� res �ߵ�β������һ��ʼ׼���õġ��� b ���ڵ�����������
        while(res -> next != nullptr) {
            res = res -> next;
        }
        res -> next = sign;
        return cur -> next;
    }
};
