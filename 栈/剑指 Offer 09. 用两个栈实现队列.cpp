/*
用两个栈实现一个队列。队列的声明如下，请实现它的两个函数 appendTail 和 deleteHead ，分别完成在队列尾部插入整数和在队列头部删除整数的功能。
(若队列中没有元素，deleteHead 操作返回 -1 )


示例 1：
输入：
["CQueue","appendTail","deleteHead","deleteHead"]
[[],[3],[],[]]
输出：[null,null,3,-1]

示例 2：
输入：
["CQueue","deleteHead","appendTail","appendTail","deleteHead","deleteHead"]
[[],[],[5],[2],[],[]]
输出：[null,-1,null,null,5,2]

提示：
1 <= values <= 10000
最多会对?appendTail、deleteHead 进行 10000 次调用
*/


// 这道题的题目描述我硬是看不懂，后来看了评论才理解：
// 两列输入中每一个数组元素是一一对应的，看示例1：
// "CQueue" 对应 [] ，表明要创建一个队列，无参数，无返回值；
// "appendTail" 对应 [3] ，表明给队列添加一个元素，参数值为3，无返回值；
// "deleteHead" 对应 [] ，表明要删除队首元素，无参数，返回值为删除的元素。
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
