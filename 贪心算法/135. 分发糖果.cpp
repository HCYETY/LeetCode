老师想给孩子们分发糖果，有 N?个孩子站成了一条直线，老师会根据每个孩子的表现，预先给他们评分。

你需要按照以下要求，帮助老师给这些孩子分发糖果：

每个孩子至少分配到 1 个糖果。
评分更高的孩子必须比他两侧的邻位孩子获得更多的糖果。
那么这样下来，老师至少需要准备多少颗糖果呢？

输入：[1,0,2]
输出：5
解释：你可以分别给这三个孩子分发 2、1、2 颗糖果。

输入：[1,2,2]
输出：4
解释：你可以分别给这三个孩子分发 1、2、1 颗糖果。
     第三个孩子只得到 1 颗糖果，这已满足上述两个条件。


class Solution {
public:
    int candy(vector<int>& ratings) {
        int size = ratings.size();
        if(size<2) {
            return size;
        }
        vector<int> num(size,1);
        for(int i=1; i<size; i++) {
            if(ratings[i] > ratings[i-1]) {
                num[i] = num[i-1] + 1;
            }
        }
        for(int i=size-1; i>0; i--) {
            if(ratings[i]<ratings[i-1]) {
                num[i-1] = max(num[i-1], num[i]+1);
            }
        }
        return accumulate(num.begin(), num.end(), 0);
    }
};
