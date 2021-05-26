/*
�����������飬arr1 �� arr2��
��arr2 �е�Ԫ�ظ�����ͬ
��arr2 �е�ÿ��Ԫ�ض������� arr1 ��
�� arr1 �е�Ԫ�ؽ�������ʹ arr1 ��������˳��� arr2 �е����˳����ͬ��δ�� arr2 �г��ֹ���Ԫ����Ҫ����������� arr1 ��ĩβ��

ʾ����
���룺arr1 = [2,3,1,3,2,4,6,7,9,2,19], arr2 = [2,1,4,3,9,6]
�����[2,2,2,1,4,3,3,9,6,7,19]

��ʾ��
1 <= arr1.length, arr2.length <= 1000
0 <= arr1[i], arr2[i] <= 1000
arr2?�е�Ԫ��?arr2[i]?������ͬ
arr2 �е�ÿ��Ԫ��?arr2[i]?��������?arr1?��
*/

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
//    	max_element����������ѯ���ֵ���ڵĵ�һ��λ�á�
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
