/*
输入整数数组 arr ，找出其中最小的 k 个数。
例如，输入4、5、1、6、2、7、3、8这8个数字，则最小的4个数字是1、2、3、4。

示例 1：
输入：arr = [3,2,1], k = 2
输出：[1,2] 或者 [2,1]

示例 2：
输入：arr = [0,1,2,1], k = 1
输出：[0]

限制：
0 <= k <= arr.length <= 10000
0 <= arr[i] <= 10000
*/


// 直接排就完事了
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());
        vector<int> res(k);
        for(int i = 0; i < k; i++) {
            res[i] = arr[i];
        }
        return res;
    }
};
// 用最大堆排前 k 个
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int> res(k, 0);
        if (k == 0) { // 排除 0 的情况
            return res;
        }
        priority_queue<int> myquque;
        for(int i = 0; i < k; i++) {
            myquque.push(arr[i]);
        }
        for(int i = k; i < arr.size(); i++) {
            if(myquque.top() > arr[i]) {
                myquque.pop();
                myquque.push(arr[i]);
            }
        }
        for(int i = 0; i < k; i++) {
            res[i] = myquque.top();
            myquque.pop();
        }
        return res;
    }
};
