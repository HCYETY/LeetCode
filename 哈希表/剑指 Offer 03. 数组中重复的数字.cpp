/*
��һ������Ϊ n ������ nums ����������ֶ��� 0��n-1 �ķ�Χ�ڡ�
������ĳЩ�������ظ��ģ�����֪���м��������ظ��ˣ�Ҳ��֪��ÿ�������ظ��˼��Ρ�
���ҳ�����������һ���ظ������֡�

ʾ�� 1��
���룺[2, 3, 1, 0, 2, 5, 3]
�����2 �� 3

���ƣ�
2 <= n <= 100000
*/


// �ⷨһ�������ס���Ϊ
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
         sort(nums.begin(), nums.end());
         for (int i = 1; i < nums.size(); i++) {
             if (nums[i] == nums[i-1]) {
                 return nums[i];
             }
         }
         return -1;
    }
};
// �ⷨ������ϣ���ʶ
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        unordered_map <int, bool> um;
        for (int num : nums) {
            if (um[num]) return num;
            um[num] = true;
        }
        return -1;
    }
};
// �ⷨ����ԭ�ؽ���
// ˼·��������������У���һ���������� x ʱ�����佻�������� x ����
// �����ڶ����������� x ʱ��һ���� nums[x] = x ����ʱ���ɵõ�һ���ظ����֡�
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        int i = 0;
        while (i < nums.size()) {
            // ���������ڶ�Ӧ����λ�ã����轻�����������
            if (nums[i] == i) {
                i++;
                continue;
            }
            // ���� nums[i] �������� i ����Ԫ��ֵ��Ϊ nums[i] �����ڶ����������֣���ʱ�ҵ�һ���ظ�ֵ�����ش�ֵ nums[i]
            if (nums[nums[i]] == nums[i]) {
                return nums[i];
            }
            // ��һ���������֣���������Ϊ i �� nums[i] ��Ԫ��ֵ���������ֽ�������Ӧ����λ��
            swap(nums[i], nums[nums[i]]);
        }
        return -1;
    }
};
