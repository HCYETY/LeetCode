/*
给你一个数组 prices ，其中 prices[i] 是商店里第 i 件商品的价格。
商店里正在进行促销活动，如果你要买第 i 件商品，那么你可以得到与 prices[j] 相等的折扣。
其中 j 是满足 j > i 且 prices[j] <= prices[i] 的 最小下标 ，如果没有满足条件的 j ，你将没有任何折扣。

请你返回一个数组，数组中第 i 个元素是折扣后你购买商品 i 最终需要支付的价格。

示例 1：
输入：prices = [8,4,6,2,3]
输出：[4,2,4,2,3]
解释：
商品 0 的价格为 price[0]=8 ，你将得到 prices[1]=4 的折扣，所以最终价格为 8 - 4 = 4 。
商品 1 的价格为 price[1]=4 ，你将得到 prices[3]=2 的折扣，所以最终价格为 4 - 2 = 2 。
商品 2 的价格为 price[2]=6 ，你将得到 prices[3]=2 的折扣，所以最终价格为 6 - 2 = 4 。
商品 3 和 4 都没有折扣。

示例 2：
输入：prices = [1,2,3,4,5]
输出：[1,2,3,4,5]
解释：在这个例子中，所有商品都没有折扣。

示例 3：
输入：prices = [10,1,1,6]
输出：[9,0,1,6]

提示：
1 <= prices.length <= 500
1 <= prices[i] <= 10^3
*/


class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        //维护一个价格单调递增的栈存储索引值
        //若当前价格小于栈顶所指价格，则栈顶索引值出栈，计算该索引处折扣后的价格，直到栈为空或当前价格大于栈顶所指价格
        //将当前索引入栈
        if(prices.empty()) return {};
        stack<int> s;
        int len=prices.size();
        vector<int> ans(len);
        s.push(0); //将第一个元素的索引入栈
        for(int i=1;i<len;++i) {
            while(!s.empty()&&prices[i]<=prices[s.top()]) {
                ans[s.top()]=prices[s.top()]-prices[i]; //计算折扣后的价格
                s.pop(); //出栈
            }
            s.push(i);
        }
        while(!s.empty()) { //剩余的是没有折扣的
            ans[s.top()]=prices[s.top()];
            s.pop();
        }
        return ans;
    }
};
