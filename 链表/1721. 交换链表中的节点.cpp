/*
给你链表的头节点 head 和一个整数 k 。
交换 链表正数第 k 个节点和倒数第 k 个节点的值后，返回链表的头节点（链表 从 1 开始索引）。

示例 1：
输入：head = [1,2,3,4,5], k = 2
输出：[1,4,3,2,5]

示例 2：
输入：head = [7,9,6,6,7,8,3,0,9,5], k = 5
输出：[7,9,6,6,8,7,3,0,9,5]

示例 3：
输入：head = [1], k = 1
输出：[1]

示例 4：
输入：head = [1,2], k = 1
输出：[2,1]

示例 5：
输入：head = [1,2,3], k = 2
输出：[1,2,3]

提示：
链表中节点的数目是 n
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
// 双指针
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
//一开始的做法，是想交换两个节点的，后来看了题解，只交换节点值（行吧，我认了）
//最后这种做法行不通，不知道问题出在哪里，但毕竟是心血，还是贴在后面吧
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        if(head == nullptr) {
            return head;
        }
        // 为了得到链表的长度
        int length = 0;
        ListNode* cur = head;
        while(cur != nullptr) {
            length++;
            cur = cur -> next;
        }
        // 新建链表1 找两个目标节点
        int len = 0;
        ListNode* sign = head, * pre = nullptr, * lat = nullptr;
        while(sign != nullptr) {
            len++;
            // 找到第 k 个节点
            if(len == k) {
                pre = sign;
            }
            // 找到倒数第k个节点，并替换成第k个节点
            if(len == length - k) {
                lat = sign -> next;
                sign -> next = pre;
                pre -> next = sign -> next -> next;
                break;
            }
            sign = sign -> next;
        }
        // 新建链表2 替换成 倒数第k个节点
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
