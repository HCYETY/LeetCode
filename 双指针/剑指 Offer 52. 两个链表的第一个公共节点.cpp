/*
输入两个链表，找出它们的第一个公共节点。

示例 1：
输入：intersectVal = 8, listA = [4,1,8,4,5], listB = [5,0,1,8,4,5], skipA = 2, skipB = 3
输出：Reference of the node with value = 8
输入解释：相交节点的值为 8 （注意，如果两个列表相交则不能为 0）。从各自的表头开始算起，链表 A 为 [4,1,8,4,5]，链表 B 为 [5,0,1,8,4,5]。在 A 中，相交节点前有 2 个节点；在 B 中，相交节点前有 3 个节点。

示例 2：
输入：intersectVal?= 2, listA = [0,9,1,2,4], listB = [3,2,4], skipA = 3, skipB = 1
输出：Reference of the node with value = 2
输入解释：相交节点的值为 2 （注意，如果两个列表相交则不能为 0）。从各自的表头开始算起，链表 A 为 [0,9,1,2,4]，链表 B 为 [3,2,4]。在 A 中，相交节点前有 3 个节点；在 B 中，相交节点前有 1 个节点。

示例 3：
输入：intersectVal = 0, listA = [2,6,4], listB = [1,5], skipA = 3, skipB = 2
输出：null
输入解释：从各自的表头开始算起，链表 A 为 [2,6,4]，链表 B 为 [1,5]。由于这两个链表不相交，所以 intersectVal 必须为 0，而 skipA 和 skipB 可以是任意值。
解释：这两个链表不相交，因此返回 null。

注意：
如果两个链表没有交点，返回 null.
在返回结果后，两个链表仍须保持原有的结构。
可假定整个链表结构中没有循环。
程序尽量满足 O(n) 时间复杂度，且仅用 O(1) 内存。
*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// 解法一：哈希集合
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
// 解法二：双指针
// 设 headA 的不相交部分有 a 个节点，headB 的不相交部分有 b 个节点，两个链表相交的部分有 c 个节点
// 每次遍历时两个链表都指向下一个节点
// 1.如果链表相交且等长，则两个指针会同时到达两个链表的第一个公共节点，此时返回两个链表的第一个公共节点；
// 2.如果链表相交且不等长，那么
//   2.1 当 headA 被遍历完后接上 headB 然后继续遍历，此时指针移动了 a+c+b 次
//   2.2 当 headB 被遍历完后接上 headA 然后继续遍历，此时指针移动了 b+c+a 次
//   2.3 这时两个指针会同时到达两个链表的第一个公共节点，该节点也是两个指针第一次同时指向的节点，此时返回两个链表的第一个公共节点。
// 3.如果链表不相交且等长，则两个指针会同时到达两个链表的尾节点，然后同时变成空值 null，此时返回 null；
// 4.如果链表不相交且不等长，那么
//   4.1 由于两个链表没有公共节点，两个指针也不会同时到达两个链表的尾节点，因此两个指针都会遍历完两个链表
//   4.2 headA 指针移动了 m+n 次、headB 移动了 n+m 次之后，两个指针会同时变成空值 null，此时返回 null。
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
