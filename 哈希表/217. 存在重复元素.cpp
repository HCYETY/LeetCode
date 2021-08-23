/*
����һ���������飬�ж��Ƿ�����ظ�Ԫ�ء�
�������һֵ�������г����������Σ��������� true �����������ÿ��Ԫ�ض�����ͬ���򷵻� false ��

ʾ�� 1:
����: [1,2,3,1]
���: true

ʾ�� 2:
����: [1,2,3,4]
���: false

ʾ�� 3:
����: [1,1,1,3,3,4,3,2,4,2]
���: true
*/


// �ⷨһ������
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
         sort(nums.begin(), nums.end());
         for (int i = 1; i < nums.size(); i++) {
             if (nums[i] == nums[i-1]) {
                 return true;
             }
         }
         return false;
    }
};
// �ⷨ������ϣ��
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
         unordered_set<int> s;
         for (int number : nums) {
             if (s.find(number) != s.end()) {
                 return true;
             }
             s.insert(number);
         }
         return false;
    }
};
// �ⷨ���������ʶ��������Ӧ���ǿ��Եģ�����֪��Ϊʲô����ͨ����
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int len = nums.size();
        vector <int> dp(len, 0);
        for (int i = 0; i < len; i++) {
            dp[nums[i]]++;
            if(dp[nums[i]] > 1) {
                return true;
            }
        }
        return false;
    }
};
