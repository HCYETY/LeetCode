/*
请根据每日 气温 列表 temperatures ，重新生成一个列表，要求其对应位置的输出为：要想观测到更高的气温，至少需要等待的天数。
如果气温在这之后都不会升高，请在该位置用 0 来代替。

示例 1:
输入: temperatures = [73,74,75,71,69,72,76,73]
输出: [1,1,4,2,1,1,0,0]

示例 2:
输入: temperatures = [30,40,50,60]
输出: [1,1,1,0]

示例 3:
输入: temperatures = [30,60,90]
输出: [1,1,0]

提示：
1 <= temperatures.length <= 105
30 <= temperatures[i] <= 100
*/


class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int len = temperatures.size();
        vector <int> res(len, 0);
        stack <int> stk;
		  // 这里需要从数组的末位置开始遍历，以便栈的维护
        for (int i = len - 1; i >= 0; i --) {
	        	// 维护一个最新的高气温的单调栈
            while (!stk.empty() && temperatures[i] >= temperatures[stk.top()])
                stk.pop();
				// 得到 符合条件的元素与当前元素的距离
            if (!stk.empty())
                res[i] = stk.top() - i;
				// 始终将元素下标压入栈
            stk.push(i);
        }
        return res;
    }
};
