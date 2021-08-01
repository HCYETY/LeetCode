/*
给你两个 非空 链表来代表两个非负整数。数字最高位位于链表开始位置。它们的每个节点只存储一位数字。
将这两数相加会返回一个新的链表。
你可以假设除了数字 0 之外，这两个数字都不会以零开头。

示例1：
输入：l1 = [7,2,4,3], l2 = [5,6,4]
输出：[7,8,0,7]

示例2：
输入：l1 = [2,4,3], l2 = [5,6,4]
输出：[8,0,7]

示例3：
输入：l1 = [0], l2 = [0]
输出：[0]

提示：
链表的长度范围为 [1, 100]
0 <= node.val <= 9
输入数据保证链表代表的数字无前导 0

进阶：如果输入链表不能修改该如何处理？换句话说，不能对列表中的节点进行翻转。
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
		  // 将链表节点值压入栈
        stack <int> stk1, stk2;
        while(l1) {
            stk1.push(l1 -> val);
            l1 = l1 -> next;
        }
        while(l2) {
            stk2.push(l2 -> val);
            l2 = l2 -> next;
        }
        // 标识是否进位
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
            // 反转链表
            curnode -> next = ans;
            ans = curnode;
        }
        return ans;
    }
};
