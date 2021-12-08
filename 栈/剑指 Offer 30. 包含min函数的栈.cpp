/*
����ջ�����ݽṹ�����ڸ�������ʵ��һ���ܹ��õ�ջ����СԪ�ص� min �����ڸ�ջ�У����� min��push �� pop ��ʱ�临�Ӷȶ��� O(1)��

ʾ��:
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.min();   --> ���� -3.
minStack.pop();
minStack.top();      --> ���� 0.
minStack.min();   --> ���� -2.

��ʾ��
�������ĵ����ܴ��������� 20000 ��
*/


class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> stk;
    stack<int> assist;
    MinStack() {
        assist.push(INT_MAX);
    }

    void push(int x) {
        stk.push(x);
        assist.push(::min(assist.top(), x));
    }

    void pop() {
        stk.pop();
        assist.pop();
    }

    int top() {
        return stk.top();
    }

    int min() {
        return assist.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();

