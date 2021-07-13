/*  237.删除链表中的节点
请编写一个函数，使其可以删除某个链表中给定的（非末尾）节点。传入函数的唯一参数为 要被删除的节点 。
现有一个链表 -- head = [4,5,1,9]，它可以表示为:

示例 1：
输入：head = [4,5,1,9], node = 5
输出：[4,1,9]
解释：给定你链表中值为 5 的第二个节点，那么在调用了你的函数之后，该链表应变为 4 -> 1 -> 9.

示例 2：
输入：head = [4,5,1,9], node = 1
输出：[4,5,9]
解释：给定你链表中值为 1 的第三个节点，那么在调用了你的函数之后，该链表应变为 4 -> 5 -> 9.

提示：
链表至少包含两个节点。
链表中所有节点的值都是唯一的。
给定的节点为非末尾节点并且一定是链表中的一个有效节点。
不要从你的函数中返回任何结果。
*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
		  // 原则上，链表问题只修改指针，不直接修改链表的节点值。但这道题直接修改，就当特殊情况特殊处理吧
        node -> val = node -> next -> val;
        node -> next = node -> next -> next;
    }
};




/*  面试题 02.03. 删除中间节点
若链表中的某个节点，既不是链表头节点，也不是链表尾节点，则称其为该链表的「中间节点」。
假定已知链表的某一个中间节点，请实现一种算法，将该节点从链表中删除。

例如，传入节点 c（位于单向链表 a->b->c->d->e->f 中），将其删除后，剩余链表为 a->b->d->e->f

示例：
输入：节点 5 （位于单向链表 4->5->1->9 中）
输出：不返回任何数据，从链表中删除传入的节点 5，使链表变为 4->1->9
*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        node -> val = node -> next -> val;
        node -> next = node -> next -> next;
    }
};
