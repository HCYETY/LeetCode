/*
����һ���������� A������������е�ÿ��Ԫ�� A[i] ������һ���������� x ��-K <= x <= K�����Ӷ��õ�һ�������� B ��
�������� B �����ֵ����Сֵ֮����ܴ��ڵ���С��ֵ��

ʾ�� 1��
���룺A = [1], K = 0
�����0
���ͣ�B = [1]

ʾ�� 2��
���룺A = [0,10], K = 2
�����6
���ͣ�B = [2,8]

ʾ�� 3��
���룺A = [1,3,6], K = 3
�����0
���ͣ�B = [3,3,3] �� B = [4,4,4]

��ʾ��
1 <= A.length <= 10000
0 <= A[i] <= 10000
0 <= K <= 10000
*/


//û�����ǰ��
class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        int len = nums.size();
        if(len < 2) return 0;
        int diff = 0, max = 0, min = 0;
        sort(nums.begin(), nums.end());
        if(nums[len - 1] - nums[0] >= nums[0] + k) {
            nums[0] += k;
            nums[len-1] -= k;
            diff = nums[len-1] - nums[0];
            if(diff < 0) diff = 0;
        }
        return diff;
    }
};
//��������
/* ˼·��
Ҫ�õ���С��ֵ���� max(B)-min(B)����Ӧʹԭ����A�����ֵ����Сֵ�����ӽ���
��max(A)��min(A)�Ĳ�ֵ����2K�����ڱ任��Ӧʹmax(A)-K, min(A)+K����ʱ���Ϊmax(A)-min(A)-2K��
����ֵС�ڵ���2*K,���ʹ���ս��Ϊ0��
*/
class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        if(nums[nums.size()-1] - nums[0] > 2 * k)
            return nums[nums.size()-1] - nums[0] - 2 * k;
				// �ȼ��� return (nums[nums.size() - 1] - k) - (nums[0] + k);
        return 0;
    }
};
