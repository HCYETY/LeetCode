/*
编写代码，移除未排序链表中的重复节点。保留最开始出现的节点。

示例1:
输入：[1, 2, 3, 3, 2, 1]
输出：[1, 2, 3]
 
示例2:
输入：[1, 1, 1, 1, 2]
输出：[1, 2]

提示：
链表长度在[0, 20000]范围内。
链表元素在[0, 20000]范围内。

进阶：
如果不得使用临时缓冲区，该怎么解决？
*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// 方法一：哈希存值
class Solution {
public:
    ListNode* removeDuplicateNodes(ListNode* head) {
        if(!head) return head;
        unordered_set<int> occurred = {head -> val};
        ListNode * cur = head;
        while(cur -> next != nullptr) {
            ListNode * pos = cur -> next;
            if(!occurred.count(pos -> val)) {
                occurred.insert(pos -> val);
                cur = cur -> next;
            } else {
                cur -> next = cur -> next -> next;
            }
        }
        // cur -> next = nullptr;
        return head;
    }
};
// 进阶版：类似于冒泡循环 --> 时间换空间 O_o??
class Solution {
public:
    ListNode* removeDuplicateNodes(ListNode* head) {
        ListNode* cur = head;
        while (cur != nullptr) {
            ListNode* pos = cur;
            while (pos->next != nullptr) {
                if (pos->next->val == cur->val) {
                    pos->next = pos->next->next;
                } else {
                    pos = pos->next;
                }
            }
            cur = cur -> next;
        }
        return head;
    }
};
