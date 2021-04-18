/*
给定两个整数数组，请交换一对数值（每个数组中取一个数值），使得两个数组所有元素的和相等。
返回一个数组，第一个元素是第一个数组中要交换的元素，第二个元素是第二个数组中要交换的元素。若有多个答案，返回任意一个均可。若无满足条件的数值，返回空数组。

输入: array1 = [4, 1, 2, 1, 1, 2], array2 = [3, 6, 3, 3]
输出: [1, 3]

输入: array1 = [1, 2, 3], array2 = [4, 5, 6]
输出: []

提示：
1 <= array1.length, array2.length <= 100000
*/


class Solution {
public:
    vector<int> findSwapValues(vector<int>& array1, vector<int>& array2) {
        set <int> s;
        int sum1=0, sum2=0;
        for(int i=0; i<array1.size(); i++) {
            sum1 += array1[i];
        }
        for(int i=0; i<array2.size(); i++) {
            sum2 += array2[i];
            s.insert(array2[i]);
        }
        if(abs(sum1-sum2) % 2 == 1)  //abs取绝对值
            return {};  //奇数直接返回空数组
        int avg = abs(sum1 - sum2) / 2;
        for(int i=0; i<array1.size(); i++) {
            // for(j=0; j<array2.size(); j++) {
            //     if(array2[j] + array1[i] == flag )
            //         break;
            if(s.find(array1[i]+avg)!=s.end())      //找到了就返回这俩数就行了
                return {array1[i],array1[i]+avg}; //这里用array[i]+n代替array2里需要交换的数，秒！
        }
        return {};  //没找到返回空数组
    }
};
