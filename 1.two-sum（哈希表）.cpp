����һ���������� nums ��һ������Ŀ��ֵ target�������ڸ��������ҳ���ΪĿ��ֵ�����������������������ǵ������±ꡣ
����Լ���ÿ������ֻ���Ӧһ���𰸡����ǣ�������ͬһ��Ԫ���ڴ��ﲻ���ظ����֡�

����԰�����˳�򷵻ش𰸡�

ʾ�� 1��
���룺nums = [2,7,11,15], target = 9
�����[0,1]
���ͣ���Ϊ nums[0] + nums[1] == 9 ������ [0, 1] ��

ʾ�� 2��
���룺nums = [3,2,4], target = 6
�����[1,2]

ʾ�� 3��
���룺nums = [3,3], target = 6
�����[0,1]


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i, j;
        int len = nums.size();
        for(i = 0; i < len-1; i++) {
            for(j = i + 1; j < len; j++) {
                if(nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }
        return {i,j};
    }
};
