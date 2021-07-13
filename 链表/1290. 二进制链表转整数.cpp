/*
给你一个单链表的引用结点 head。链表中每个结点的值不是 0 就是 1。
已知此链表是一个整数数字的二进制表示形式。
请你返回该链表所表示数字的 十进制值 。

示例 1：
输入：head = [1,0,1]
输出：5
解释：二进制数 (101) 转化为十进制数 (5)

示例 2：
输入：head = [0]
输出：0

示例 3：
输入：head = [1]
输出：1

示例 4：
输入：head = [1,0,0,1,0,0,1,1,1,0,0,0,0,0,0]
输出：18880

示例 5：
输入：head = [0,0]
输出：0

提示：
链表不为空。
链表的结点总数不超过 30。
每个结点的值不是 0 就是 1。
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
// 解法一：先求出链表的长度，再求数字的十进制数
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        ListNode * cur = head;
        int count = 0, res = 0;
        while(cur != nullptr) {
            count++;
            cur = cur -> next;
        }
        cur = head;
        while(cur != nullptr) {
            res += (cur -> val) * pow(2, count - 1);
            count--;
            cur = cur -> next;
        }
        return res;
    }
};
// 解法二：不用求链表长度，在遍历一遍链表的同时得到数字的十进制值
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        ListNode* cur = head;
        int ans = 0;
        while (cur != nullptr) {
            ans = ans * 2 + cur->val;
            cur = cur -> next;
        }
        return ans;
    }
};
