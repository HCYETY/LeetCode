/*
设计一个找到数据流中第 k 大元素的类（class）。注意是排序后的第 k 大元素，不是第 k 个不同的元素。

请实现 KthLargest 类：
KthLargest(int k, int[] nums) 使用整数 k 和整数流 nums 初始化对象。
int add(int val) 将 val 插入数据流 nums 后，返回当前数据流中第 k 大的元素。

示例：
输入：
["KthLargest", "add", "add", "add", "add", "add"]
[[3, [4, 5, 8, 2]], [3], [5], [10], [9], [4]]
输出：
[null, 4, 5, 5, 8, 8]
解释：
KthLargest kthLargest = new KthLargest(3, [4, 5, 8, 2]);
kthLargest.add(3);   // return 4
kthLargest.add(5);   // return 5
kthLargest.add(10);  // return 5
kthLargest.add(9);   // return 8
kthLargest.add(4);   // return 8

提示：
1 <= k <= 104
0 <= nums.length <= 104
-104 <= nums[i] <= 104
-104 <= val <= 104
最多调用 add 方法 104 次
题目数据保证，在查找第 k 大元素时，数组中至少有 k 个元素
*/


class KthLargest {
public:
// priority_queue 模板有 3 个参数，其中两个有默认的参数；
// 第一个参数是存储对象的类型，第二个参数是存储元素的底层容器，第三个参数是函数对象，它定义了一个用来决定元素顺序的断言。
// 因此模板类型是：template <typename T, typename Container=std::vector<T>, typename Compare=std::less<T>> class priority_queue

//	函数对象类型 less<T> 是一个默认的排序断言，定义在头文件 function 中，决定了容器中最大的元素会排在队列前面。
//fonction 中定义了  greater<T>，用来作为模板的最后一个参数对元素排序，最小元素会排在队列前面。当然，如果指定模板的最巵一个参数，就必须提供另外的两个模板类型参数。
	 priority_queue<int, vector<int>, greater<int>> myqueue;
    int _k;

    KthLargest(int k, vector<int>& nums) {
        _k = k;
        for(int i : nums) {
            add(i);
        }
    }

    int add(int val) {
        myqueue.push(val);
        if(myqueue.size() > _k) {
            myqueue.pop();
        }
        return myqueue.top();
    }
};
/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
