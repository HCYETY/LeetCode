/*
给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。
进阶：你能尝试使用一趟扫描实现吗？

示例 1：
输入：head = [1,2,3,4,5], n = 2
输出：[1,2,3,5]

示例 2：
输入：head = [1], n = 1
输出：[]

示例 3：
输入：head = [1,2], n = 1
输出：[1]

提示：
链表中结点的数目为 sz
1 <= sz <= 30
0 <= Node.val <= 100
1 <= n <= sz
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
// 解法一：计算链表长度
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
		  // 先计算出链表的长度
        int len = 0;
        ListNode* cur = head;
        while(cur) {
            len++;
            cur = cur -> next;
        }
        // 新建一个链表
        ListNode* res = new ListNode(0);
        res -> next = head;
        ListNode* sign = res;
        // 到第n个节点的前一个节点退出循环
        for(int i = 0; i < len - n; i++) {
            sign = sign -> next;
        }
        // 修改节点的指向，指向第n个节点的下一个节点
        sign -> next = sign -> next -> next;
        return res -> next;
    }
};
// 解法二：使用栈
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* res = new ListNode(0, head);
        stack<ListNode*> stk;
        ListNode* cur = res;
        // 将整个链表压入栈中
        while (cur) {
            stk.push(cur);
            cur = cur->next;
        }
        // 移除倒数第 n 个节点
        for (int i = 0; i < n; ++i) {
            stk.pop();
        }
        // 倒数第n个节点的前一个节点 指向 倒数第n个节点的后一个节点
        ListNode* prev = stk.top();
        prev->next = prev->next->next;
        return res -> next;
        // 或者最后的返回值：
        // ListNode* ans = res->next;
        // delete res;
        // return ans;
    }
};
// 解法三：双指针
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* cur = new ListNode(0);
        cur -> next = head;
		  // 设置快慢指针，当 fast 指针走到 倒数第n个节点 的前一个节点时，退出循环
        ListNode* slow = cur;
        ListNode* fast = cur;
        for( int i = 0 ; i <= n ; i ++ ){
            fast = fast->next;
        }
        // 此时fast指针已经停下来，让slow、fast指针再统一步长往后移，直到fast指针走到尾结点
        // 此时slow指针就已经走到 倒数第n个节点的前一个节点 了
        while(fast){
            slow = slow -> next;
            fast = fast -> next;
        }
        // 于是可以直接删除目标节点
        slow -> next = slow -> next -> next;
        ListNode* retNode = cur->next;
        delete cur;
        return retNode;
		  // return cur -> next;
    }
};
