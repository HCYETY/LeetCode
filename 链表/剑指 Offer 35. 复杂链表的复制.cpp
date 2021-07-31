/*
��ʵ�� copyRandomList ����������һ����������
�ڸ��������У�ÿ���ڵ������һ�� next ָ��ָ����һ���ڵ㣬����һ�� random ָ��ָ�������е�����ڵ���� null��

ʾ�� 1��
���룺head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
�����[[7,null],[13,0],[11,4],[10,2],[1,0]]

ʾ�� 2��
���룺head = [[1,1],[2,1]]
�����[[1,1],[2,1]]

ʾ�� 3��
���룺head = [[3,null],[3,0],[3,null]]
�����[[3,null],[3,0],[3,null]]

ʾ�� 4��
���룺head = []
�����[]
���ͣ�����������Ϊ�գ���ָ�룩����˷��� null��

��ʾ��
-10000 <= Node.val <= 10000
Node.random Ϊ�գ�null����ָ�������еĽڵ㡣
�ڵ���Ŀ������ 1000 ��
*/


/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr) return nullptr;
        Node* cur = head;
        unordered_map <Node*, Node*> map;
        // 1. ���Ƹ��ڵ㣬������ ��ԭ�ڵ� -> �½ڵ㡱 �� Map ӳ��
        while(cur != nullptr) {
            map[cur] = new Node(cur->val);
            cur = cur -> next;
        }
        cur = head;  // ����cur
        // 2. ����������� next �� random ָ��
        while(cur != nullptr) {
            map[cur] -> next = map[cur->next];
            map[cur] -> random = map[cur->random];
            cur = cur -> next;
        }
        // 3. �����������ͷ�ڵ�
        return map[head];
    }
};
