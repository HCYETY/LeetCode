/*
��������һ�����ֳ��ֵĴ����������鳤�ȵ�һ�룬���ҳ�������֡�

����Լ��������Ƿǿյģ����Ҹ������������Ǵ��ڶ���Ԫ�ء�

ʾ�� 1:
����: [1, 2, 3, 2, 2, 2, 5, 4, 2]
���: 2

���ƣ�
1 <= ���鳤�� <= 50000
*/


// ���Ž⣺Ħ��ͶƱ��
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int num = 0, count = 0;
        for(int i : nums) {
            if(count == 0) num = i;
            count += i == num ? 1 : -1;
				// �ȼ���votes = votes + ( i == num ? 1 : -1);
        }
        return num;
    }
};
// �����м�λ�õ��� ���� ���ִ��������Ǹ�����Ҳ���� �������鳤�ȵ�һ�����
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size()/2];
    }
};
// ��ϣ
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map <int,int> arr;
        for(int i : nums) {
            arr[i]++;
            if(arr[i] > nums.size() / 2) {
                return i;
            }
        }
        return -1;
    }
};
