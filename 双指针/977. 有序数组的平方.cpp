/*
����һ���� �ǵݼ�˳�� ������������� nums������ ÿ�����ֵ�ƽ�� ��ɵ������飬Ҫ��Ҳ�� �ǵݼ�˳�� ����

ʾ�� 1��
���룺nums = [-4,-1,0,3,10]
�����[0,1,9,16,100]
���ͣ�ƽ���������Ϊ [16,1,0,9,100]
����������Ϊ [0,1,9,16,100]

ʾ�� 2��
���룺nums = [-7,-3,2,3,11]
�����[4,9,9,49,121]

��ʾ��
1 <= nums.length <= 104
-104 <= nums[i] <= 104
nums �Ѱ� �ǵݼ�˳�� ����

���ף�
�������ʱ�临�Ӷ�Ϊ O(n) ���㷨���������
*/


//ֱ��ƽ��������
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans;
        for (int num: nums) {
            ans.push_back(num * num);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
//˫ָ��
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        for (int i = 0, j = n - 1, pos = n - 1; i <= j;) {
            if (nums[i] * nums[i] > nums[j] * nums[j]) {
                ans[pos] = nums[i] * nums[i];
                i++;
            } else {
                ans[pos] = nums[j] * nums[j];
                j--;
            }
            pos--;
        }
        return ans;
    }
};

