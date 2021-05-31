/*
����һ����������ɵ����� nums ������ nums ��һ�� ���� �������������Ԫ�غ͡�
�������������е�һ�������������С�
��֪������ [numsl, numsl+1, ..., numsr-1, numsr] ���������� i��l <= i < r����numsi < numsi+1 �������������һ������Ϊ ���� �����顣ע�⣬��СΪ 1 ��������Ҳ���� ���� �����顣

ʾ�� 1��
���룺nums = [10,20,30,5,10,50]
�����65
���ͣ�[5,10,50] ��Ԫ�غ��������������飬���Ԫ�غ�Ϊ 65 ��

ʾ�� 2��
���룺nums = [10,20,30,40,50]
�����150
���ͣ�[10,20,30,40,50] ��Ԫ�غ��������������飬���Ԫ�غ�Ϊ 150 ��

ʾ�� 3��
���룺nums = [12,17,15,13,10,11,12]
�����33
���ͣ�[10,11,12] ��Ԫ�غ��������������飬���Ԫ�غ�Ϊ 33 ��

ʾ�� 4��
���룺nums = [100,10,1]
�����100

��ʾ��
1 <= nums.length <= 100
1 <= nums[i] <= 100
*/


class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int sum = 0, max_sum = 0, left = 0, right = 1;
        bool sign = true;
        while(left < nums.size()) {
            // ���ȼ�����ʼλ��ֵ
            if(sign) {
                sum = 0;   // ˵�������������Ԫ�أ�sum Ҫ���¼�ֵ
                sum += nums[left];
            }
            if(right < nums.size() && nums[left] < nums[right]) {
                sum += nums[right];
                sign = false;  // ��ֹ������һ���ж���䣬���� sum ���¼�ֵ
            }
            else {
                sign = true;
            }
            left = right;
            right++;
            // �������ֵ
            max_sum = max(sum, max_sum);
        }
        return max_sum;
    }
};
