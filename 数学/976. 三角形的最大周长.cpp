/*
������һЩ�����������ȣ���ɵ����� A����������������������ɵġ������Ϊ��������ε�����ܳ���
��������γ��κ������Ϊ��������Σ����� 0��

ʾ�� 1��
���룺[2,1,2]
�����5

ʾ�� 2��
���룺[1,2,1]
�����0

ʾ�� 3��
���룺[3,2,3,4]
�����10

ʾ�� 4��
���룺[3,6,2,3]
�����8

��ʾ��
3 <= A.length <= 10000
1 <= A[i] <= 10^6
*/


class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        // forѭ��ò�Ʊ� while ѭ����
        for(int i = nums.size() - 1; i >= 2; i--) {
            if(nums[i - 2] > nums[i] - nums[i - 1]) {
                return nums[i] + nums[i - 1] + nums[i - 2];
            }
        }
        // int len = nums.size();
        // while(len >= 3) {
        //     if(nums[len - 3] > nums[len - 1] - nums[len - 2]) {
        //         return nums[len - 3] + nums[len - 1] + nums[len - 2];
        //     }
        //     len--;
        // }
        return 0;
    }
};
