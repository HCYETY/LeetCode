/*
����һ���������� nums ������Զ�������һЩ������
ÿ�β����У�ѡ������һ�� nums[i] ��ɾ��������� nums[i] �ĵ�����֮�������ɾ�� ���� ���� nums[i] - 1 �� nums[i] + 1 ��Ԫ�ء�
��ʼ��ӵ�� 0 ����������������ͨ����Щ������õ���������

ʾ�� 1��
���룺nums = [3,4,2]
�����6
���ͣ�
ɾ�� 4 ��� 4 ����������� 3 Ҳ��ɾ����
֮��ɾ�� 2 ��� 2 ���������ܹ���� 6 ��������

ʾ�� 2��
���룺nums = [2,2,3,3,3,4]
�����9
���ͣ�
ɾ�� 3 ��� 3 ������������Ҫɾ������ 2 �� 4 ��
֮���ٴ�ɾ�� 3 ��� 3 ���������ٴ�ɾ�� 3 ��� 3 ��������
�ܹ���� 9 ��������

��ʾ��
1 <= nums.length <= 2 * 104
1 <= nums[i] <= 104
*/


class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unordered_map <int, int> um;
        vector <int> dp = {0, nums[0]};
        um[nums[0]] = 1;
        for (int i = 1; i < nums.size(); i++) {
            um[nums[i]]++;
            if (nums[i] != dp.back()) {
                dp.push_back(nums[i]);
            }
        }

        int last = dp[1], len = dp.size();
        dp[1] = dp[1] * um[dp[1]];
        for(int i = 2; i < len; ++i) {
            if(dp[i] - last == 1) {
                last = dp[i];
                dp[i] = max(dp[i-1], dp[i-2] + dp[i] * um[dp[i]]);
            } else {
                last = dp[i];
                dp[i] = dp[i-1] + dp[i] * um[dp[i]];
            }
        }
        return dp[len - 1];
    }
};
