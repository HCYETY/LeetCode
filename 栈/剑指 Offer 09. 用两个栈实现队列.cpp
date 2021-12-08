/*
������ջʵ��һ�����С����е��������£���ʵ�������������� appendTail �� deleteHead ���ֱ�����ڶ���β�������������ڶ���ͷ��ɾ�������Ĺ��ܡ�
(��������û��Ԫ�أ�deleteHead �������� -1 )


ʾ�� 1��
���룺
["CQueue","appendTail","deleteHead","deleteHead"]
[[],[3],[],[]]
�����[null,null,3,-1]

ʾ�� 2��
���룺
["CQueue","deleteHead","appendTail","appendTail","deleteHead","deleteHead"]
[[],[],[5],[2],[],[]]
�����[null,-1,null,null,5,2]

��ʾ��
1 <= values <= 10000
�����?appendTail��deleteHead ���� 10000 �ε���
*/


// ��������Ŀ������Ӳ�ǿ������������������۲���⣺
// ����������ÿһ������Ԫ����һһ��Ӧ�ģ���ʾ��1��
// "CQueue" ��Ӧ [] ������Ҫ����һ�����У��޲������޷���ֵ��
// "appendTail" ��Ӧ [3] ���������������һ��Ԫ�أ�����ֵΪ3���޷���ֵ��
// "deleteHead" ��Ӧ [] ������Ҫɾ������Ԫ�أ��޲���������ֵΪɾ����Ԫ�ء�
class CQueue {
    stack<int> stack1,stack2;
public:
    CQueue() {

    }

    void appendTail(int value) {
        stack1.push(value);
    }

    int deleteHead() {
        if (stack1.empty() && stack2.empty()) {
            return -1;
        }
        if (!stack1.empty() && stack2.empty()) {
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        int ret = stack2.top();
        stack2.pop();
        return ret;
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */
