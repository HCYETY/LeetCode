/*
给定一个整数数组 asteroids，表示在同一行的小行星。
对于数组中的每一个元素，其绝对值表示小行星的大小，正负表示小行星的移动方向（正表示向右移动，负表示向左移动）。每一颗小行星以相同的速度移动。
找出碰撞后剩下的所有小行星。
碰撞规则：两个行星相互碰撞，较小的行星会爆炸。如果两颗行星大小相同，则两颗行星都会爆炸。两颗移动方向相同的行星，永远不会发生碰撞。

示例 1：
输入：asteroids = [5,10,-5]
输出：[5,10]
解释：10 和 -5 碰撞后只剩下 10 。 5 和 10 永远不会发生碰撞。

示例 2：
输入：asteroids = [8,-8]
输出：[]
解释：8 和 -8 碰撞后，两者都发生爆炸。

示例 3：
输入：asteroids = [10,2,-5]
输出：[10]
解释：2 和 -5 发生碰撞后剩下 -5 。10 和 -5 发生碰撞后剩下 10 。

示例 4：
输入：asteroids = [-2,-1,1,2]
输出：[-2,-1,1,2]
解释：-2 和 -1 向左移动，而 1 和 2 向右移动。 由于移动方向相同的行星不会发生碰撞，所以最终没有行星发生碰撞。

提示：
2 <= asteroids.length <= 104
-1000 <= asteroids[i] <= 1000
asteroids[i] != 0
*/


class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack <int> stk;
        
        // 先拿到 asteroids数组的每个元素，再根据不同情况进行不同的判断
        // 注意判断条件的整合，避免 重复（套） 判断（娃）
        for (int as : asteroids) {
            // 循环判断 boom
            while (!stk.empty() && stk.top() > 0 && stk.top() < -as) {
                stk.pop();
            }
            // 一起 boom
            if (!stk.empty() && as < 0 && stk.top() == -as) {
                stk.pop();
            }
            // push
            else if (as > 0 || stk.empty() || stk.top() < 0) {
                stk.push(as);
            }
        }
        
		  // 由于栈顶元素先被获取，故需要倒着遍历数组，这样才能从栈底到栈顶、数组从左到右正确展示
        int len = stk.size();
        vector <int> res(len);
        while(!stk.empty()) {
            res[len-1] = stk.top();
            stk.pop();
            len--;
        }
        return res;
    }
};
