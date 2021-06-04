/*
��֪���� signFunc(x) ������� x �����������ض�ֵ��
- ��� x ������������ 1 ��
- ��� x �Ǹ��������� -1 ��
- ��� x �ǵ��� 0 ������ 0 ��
����һ���������� nums ���� productΪ���� nums ������Ԫ��ֵ�ĳ˻���
���� signFunc(product) ��

ʾ�� 1��
���룺nums = [-1,-2,-3,-4,3,2,1]
�����1
���ͣ�����������ֵ�ĳ˻��� 144 ���� signFunc(144) = 1

ʾ�� 2��
���룺nums = [1,5,0,2,-3]
�����0
���ͣ�����������ֵ�ĳ˻��� 0 ���� signFunc(0) = 0

ʾ�� 3��
���룺nums = [-1,1,-1,1,-1]
�����-1
���ͣ�����������ֵ�ĳ˻��� -1 ���� signFunc(-1) = -1

��ʾ��
1 <= nums.length <= 1000
-100 <= nums[i] <= 100
*/


// ����һ���������ĸ�������Ϊż��˵��Ԫ��ֵ�ĳ˻�����������Ϊ������˵��Ϊ������
class Solution {
public:
    int arraySign(vector<int>& nums) {
        int neg = 0;
        for(int i : nums) {
           if(i == 0) return 0;
           else if(i < 0) neg++;
       }
       return neg % 2 == 0 ? 1 : -1;
    }
};
// �������� ʵʱ�ж�������
class Solution {
public:
    int arraySign(vector<int>& nums) {
        int product = 1;
        for(int i : nums) {
            if(i == 0) return 0;
            product *= (i > 0) ? 1 : -1;
        }
        return product;
    }
};
