/*
给你两个链表 list1 和 list2 ，它们包含的元素分别为 n 个和 m 个。
请你将 list1 中第 a 个节点到第 b 个节点删除，并将list2 接在被删除节点的位置。
请你返回结果链表的头指针。

示例 1：
输入：list1 = [0,1,2,3,4,5], a = 3, b = 4, list2 = [1000000,1000001,1000002]
输出：[0,1,2,1000000,1000001,1000002,5]
解释：我们删除 list1 中 第三 和 第四 个节点，并将 list2 接在该位置。

示例 2：
输入：list1 = [0,1,2,3,4,5,6], a = 2, b = 5, list2 = [1000000,1000001,1000002,1000003,1000004]
输出：[0,1,1000000,1000001,1000002,1000003,1000004,6]

提示：
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
		  // 因为“链表不能更改‘前进路线’”，因此新建链表标记 list1 第 b 个节点后的链表
		  // 当 list1 遇到第 a 个节点并将下一个指针指向 list2 后，就可以接上这段新建链表了
        ListNode* pre = list1, * sign = nullptr;
        while(pre) {
            if(count != b) {
                pre = pre -> next;
                count++;
            } else {
                sign = pre -> next;
					 // 更新 count ,方便后面重复利用
                count = 0;
                break;
            }
        }
        // 新建链表，方便处理 a==0 的情况，
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
		  // 此时 list2 已经接在 res 了上，所以让 res 走到尾，接上一开始准备好的“第 b 个节点后的链表”即可
        while(res -> next != nullptr) {
            res = res -> next;
        }
        res -> next = sign;
        return cur -> next;
    }
};
