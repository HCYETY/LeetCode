/*
给你两个数组，arr1 和 arr2，
·arr2 中的元素各不相同
·arr2 中的每个元素都出现在 arr1 中
对 arr1 中的元素进行排序，使 arr1 中项的相对顺序和 arr2 中的相对顺序相同。未在 arr2 中出现过的元素需要按照升序放在 arr1 的末尾。

示例：
输入：arr1 = [2,3,1,3,2,4,6,7,9,2,19], arr2 = [2,1,4,3,9,6]
输出：[2,2,2,1,4,3,3,9,6,7,19]

提示：
1 <= arr1.length, arr2.length <= 1000
0 <= arr1[i], arr2[i] <= 1000
arr2?中的元素?arr2[i]?各不相同
arr2 中的每个元素?arr2[i]?都出现在?arr1?中
*/

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
//    	max_element是用来来查询最大值所在的第一个位置。
        int max = *max_element(arr1.begin(), arr1.end());
        vector<int> countArray(max+1);
        for(int value : arr1) {
            countArray[value]++;
        }
        vector<int> ans;
        for(int sign : arr2) {
            for(int i = 0; i < countArray[sign]; i++) {
                ans.push_back(sign);
            }
            countArray[sign] = 0;
        }
        for(int i = 0; i <= max; i++) {
             for(int j = 0; j < countArray[i]; j++) {
                 ans.push_back(i);
             }
        }
        return ans;
    }
};
