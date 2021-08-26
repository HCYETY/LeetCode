/*
�������������ҳ����ǵĵ�һ�������ڵ㡣

ʾ�� 1��
���룺intersectVal = 8, listA = [4,1,8,4,5], listB = [5,0,1,8,4,5], skipA = 2, skipB = 3
�����Reference of the node with value = 8
������ͣ��ཻ�ڵ��ֵΪ 8 ��ע�⣬��������б��ཻ����Ϊ 0�����Ӹ��Եı�ͷ��ʼ�������� A Ϊ [4,1,8,4,5]������ B Ϊ [5,0,1,8,4,5]���� A �У��ཻ�ڵ�ǰ�� 2 ���ڵ㣻�� B �У��ཻ�ڵ�ǰ�� 3 ���ڵ㡣

ʾ�� 2��
���룺intersectVal?= 2, listA = [0,9,1,2,4], listB = [3,2,4], skipA = 3, skipB = 1
�����Reference of the node with value = 2
������ͣ��ཻ�ڵ��ֵΪ 2 ��ע�⣬��������б��ཻ����Ϊ 0�����Ӹ��Եı�ͷ��ʼ�������� A Ϊ [0,9,1,2,4]������ B Ϊ [3,2,4]���� A �У��ཻ�ڵ�ǰ�� 3 ���ڵ㣻�� B �У��ཻ�ڵ�ǰ�� 1 ���ڵ㡣

ʾ�� 3��
���룺intersectVal = 0, listA = [2,6,4], listB = [1,5], skipA = 3, skipB = 2
�����null
������ͣ��Ӹ��Եı�ͷ��ʼ�������� A Ϊ [2,6,4]������ B Ϊ [1,5]�����������������ཻ������ intersectVal ����Ϊ 0���� skipA �� skipB ����������ֵ��
���ͣ������������ཻ����˷��� null��

ע�⣺
�����������û�н��㣬���� null.
�ڷ��ؽ���������������뱣��ԭ�еĽṹ��
�ɼٶ���������ṹ��û��ѭ����
���������� O(n) ʱ�临�Ӷȣ��ҽ��� O(1) �ڴ档
*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// �ⷨһ����ϣ����
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set <ListNode *> visited;
        ListNode *temp = headA;
        while (temp) {
            visited.insert(temp);
            temp = temp -> next;
        }
        temp = headB;
        while (temp) {
            if (visited.count(temp)) {
                return temp;
            }
            temp = temp->next;
        }
        return nullptr;
    }
};
// �ⷨ����˫ָ��
// �� headA �Ĳ��ཻ������ a ���ڵ㣬headB �Ĳ��ཻ������ b ���ڵ㣬���������ཻ�Ĳ����� c ���ڵ�
// ÿ�α���ʱ��������ָ����һ���ڵ�
// 1.��������ཻ�ҵȳ���������ָ���ͬʱ������������ĵ�һ�������ڵ㣬��ʱ������������ĵ�һ�������ڵ㣻
// 2.��������ཻ�Ҳ��ȳ�����ô
//   2.1 �� headA ������������ headB Ȼ�������������ʱָ���ƶ��� a+c+b ��
//   2.2 �� headB ������������ headA Ȼ�������������ʱָ���ƶ��� b+c+a ��
//   2.3 ��ʱ����ָ���ͬʱ������������ĵ�һ�������ڵ㣬�ýڵ�Ҳ������ָ���һ��ͬʱָ��Ľڵ㣬��ʱ������������ĵ�һ�������ڵ㡣
// 3.��������ཻ�ҵȳ���������ָ���ͬʱ�������������β�ڵ㣬Ȼ��ͬʱ��ɿ�ֵ null����ʱ���� null��
// 4.��������ཻ�Ҳ��ȳ�����ô
//   4.1 ������������û�й����ڵ㣬����ָ��Ҳ����ͬʱ�������������β�ڵ㣬�������ָ�붼���������������
//   4.2 headA ָ���ƶ��� m+n �Ρ�headB �ƶ��� n+m ��֮������ָ���ͬʱ��ɿ�ֵ null����ʱ���� null��
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr) {
            return nullptr;
        }
        ListNode *pA = headA, *pB = headB;
        while (pA != pB) {
            pA = pA == nullptr ? headB : pA->next;
            pB = pB == nullptr ? headA : pB->next;
        }
        return pA;
    }
};
