����һ����������nums���±�� 0 ��ʼ����ÿһ�β����У������ѡ��������һ��Ԫ�أ�����������1��
�ȷ�˵�����nums = [1,2,3]�������ѡ������nums[1]�õ�nums = [1,3,3]��
���㷵��ʹnums�ϸ���������ٲ���������

���ǳ�����nums�� �ϸ�����ģ���������������е�0 <= i < nums.length - 1����nums[i] < nums[i+1]��һ������Ϊ 1���������ϸ������һ�����������


ʾ�� 1��
���룺nums = [1,1,1]
�����3
���ͣ�����Խ������²�����
1) ���� nums[2] �������Ϊ [1,1,2] ��
2) ���� nums[1] �������Ϊ [1,2,2] ��
3) ���� nums[2] �������Ϊ [1,2,3] ��

ʾ�� 2��
���룺nums = [1,5,2,4,1]
�����14

ʾ�� 3��
���룺nums = [8]
�����0


class Solution {
public:
    int minOperations(vector<int>& nums) {
        int len = nums.size(), runs = 0;
        if(len <= 1)
            return runs;
        for(int i = 1; i < len; i++) {
            if(nums[i-1] >= nums[i]) {
                int flag = nums[i-1] + 1 - nums[i];
                runs +=  flag;
                nums[i] = nums[i-1] + 1;
            }
        }
        return runs;
    }
};
