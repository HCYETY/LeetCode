/*
输入一个链表的头节点，从尾到头反过来返回每个节点的值（用数组返回）。

示例 1：
输入：head = [1,3,2]
输出：[2,3,1]

限制：
0 <= 链表长度 <= 10000
*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
// 解法一：反转链表法
class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
		  // cur为反转后的链表
        ListNode* cur = NULL;
        ListNode* tmp;
        while(head) {
        		// 反转链表的循环不变式
            tmp = head -> next;
            head -> next = cur;
            cur = head;
            head = tmp;
        }
		  // 更新 head 链表
        head = cur;
        vector<int> res;
        while(head) {
            res.push_back(head->val);
            head = head -> next;
        }
        return res;
    }
};
// 解法二：辅助栈法
class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        stack<int> mystack;
        while(head) {
            mystack.push(head->val);
            head = head -> next;
        } // 此时辅助栈里的值从栈底到栈顶为链表的正序
        vector<int> res;
		  // 于是将栈顶的值一个一个压入数组，就能将链表反转过来了
        while(!mystack.empty()) {
            res.push_back(mystack.top());
            mystack.pop();
        }
        return res;
    }
};
// 解法三：递归法
class Solution {
public:
    void resolve(vector<int>&res, ListNode*head) {
        if(!head) return;
        resolve(res, head->next);
        res.push_back(head->val);
    }
    vector<int> reversePrint(ListNode* head) {
        vector<int>res;
        resolve(res, head);
        return res;
    }
};
